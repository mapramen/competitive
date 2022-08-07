#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 100001
#define LOGN 16

const int INF = 1E9;

struct NodeData{
  int ans;
  int sum;
  int prefix_ans;
  int suffix_ans;
};

NodeData Invert(NodeData a){
  return {a.ans, a.sum, a.suffix_ans, a.prefix_ans};
}

NodeData Combine(NodeData a, NodeData b){
  return {
    max(a.suffix_ans + b.prefix_ans, max(a.ans, b.ans)),
    a.sum + b.sum,
    max(a.prefix_ans, a.sum + b.prefix_ans),
    max(b.suffix_ans, a.suffix_ans + b.sum),
  };
}

class Node{
  public:
  Node(int _l, int _r){
    l = _l, r = _r, lazy_update = false, lazy_update_value = 0;
    node_data = {0, 0, 0, 0};

    if(l == r){
      leftChild = NULL, rightChild = NULL;
    }
    else{
      int mid = (l + r) / 2;
      leftChild = new Node(l, mid), rightChild = new Node(mid + 1, r);
    }
  }

  NodeData Update(int ql, int qr, int x){
    if(qr < l || r < ql){
      return node_data;
    }

    if(ql <= l && r <= qr){
      lazy_update = true, lazy_update_value = x;
      int z = x * (r - l + 1);
      node_data = {max(x, z), z, max(x, z), max(x, z)};
      return node_data;
    }

    LazyUpdateChildren();

    node_data = Combine(leftChild->Update(ql, qr, x), rightChild->Update(ql, qr, x));
    return node_data;
  }

  NodeData Query(int ql, int qr){
    if(qr < ql || qr < l || r < ql){
      return {0, 0, -INF, -INF};
    }

    if(ql <= l && r <= qr){
      return node_data;
    }

    LazyUpdateChildren();
    NodeData ans = Combine(leftChild->Query(ql, qr), rightChild->Query(ql, qr));
    node_data = Combine(leftChild->node_data, rightChild->node_data);

    return ans;
  }

  private:
  int l;
  int r;
  bool lazy_update;
  int lazy_update_value;
  NodeData node_data;

  Node* leftChild;
  Node* rightChild;

  void LazyUpdateChildren(){
    if(!lazy_update){
      return;
    }

    leftChild->Update(l, r, lazy_update_value);
    rightChild->Update(l, r, lazy_update_value);
    lazy_update_value = 0, lazy_update = false;
  }
};

vector<vector<int>> adj(N), chains(N);
int a[N], parent[N], d[N], subtreeSize[N], chainNumber[N], chainLeader[N], chainPosition[N], T[LOGN + 1][N];
Node* st[N];

void Reset(int n){
  for(int i = 0; i <= n; ++i){
    adj[i].clear();
    chains[i].clear();
    
    d[i] = 0;
    chainNumber[i] = i;
  }

  for(int k = 0; k <= LOGN; ++k){
    for(int i = 0; i <= n; ++i){
      T[k][i] = 0;
    }
  }
}

void PreProcess(int n){
  for(int chainNo = 1; chainNo <= n; ++chainNo){
    vector<int>& chain = chains[chainNo];
    if(chain.empty()){
      continue;
    }
    reverse(chain.begin(), chain.end());

    chainLeader[chainNo] = chain.front();

    int chainPos = 0;
    for(int i: chain){
      chainPosition[i] = ++chainPos;
    }

    st[chainNo] = new Node(1, chainPos);
  }

  for(int i = 1; i <= n; ++i){
    st[chainNumber[i]]->Update(chainPosition[i], chainPosition[i], a[i]);
  }

  for(int i = 1; i <= n; ++i){
    T[0][i] = parent[i];
  }

  for(int k = 1; k <= LOGN; ++k){
    for(int i = 1; i <= n; ++i){
      T[k][i] = T[k - 1][T[k - 1][i]];
    }
  }
}

int KthAncestor(int k, int i){
  for(int x = LOGN; x > -1; --x){
    if((k & (1 << x))){
      i = T[x][i];
      k ^= (1 << x);
    }
  }
  return i;
}

int LCA(int i, int j){
  if(d[i] > d[j]){
    swap(i, j);
  }

  j = KthAncestor(d[j] - d[i], j);

  if(i == j){
    return i;
  }

  for(int k = LOGN; k > -1; --k){
    if(T[k][i] != T[k][j]){
      i = T[k][i], j = T[k][j];
    }
  }

  return T[0][i];
}

void DFS(int i, int p){
  parent[i] = p;
  d[i] = 1 + d[p];
  subtreeSize[i] = 1;

  int heavyChild = 0;
  for(int j: adj[i]){
    if(j == p){
      continue;
    }
    
    DFS(j, i);
    subtreeSize[i] += subtreeSize[j];

    if(subtreeSize[j] > subtreeSize[heavyChild]){
      heavyChild = j;
    }
  }

  if(heavyChild == 0){
    heavyChild = i;
  }

  chainNumber[i] = chainNumber[heavyChild];
  chains[chainNumber[i]].push_back(i);
}

NodeData QueryToAncestor(int i, int k){
  NodeData ans = {0, 0, -INF, -INF};

  while(chainNumber[i] != chainNumber[k]){
    ans = Combine(st[chainNumber[i]]->Query(1, chainPosition[i]), ans);
    i = parent[chainLeader[chainNumber[i]]];
  }

  return Combine(st[chainNumber[i]]->Query(chainPosition[k], chainPosition[i]), ans);
}

int Query(int i, int j){
  int k = LCA(i, j);

  if(k == i){
    return QueryToAncestor(j, i).ans;
  }

  if(k == j){
    return QueryToAncestor(i, j).ans;
  }

  NodeData a = QueryToAncestor(i, KthAncestor(d[i] - d[k], i));
  NodeData b = QueryToAncestor(j, KthAncestor(d[j] - d[k] - 1, j));
  return Combine(Invert(b), a).ans;
}

void UpdateToAncestor(int i, int k, int x){
  while(chainNumber[i] != chainNumber[k]){
    st[chainNumber[i]]->Update(1, chainPosition[i], x);
    i = parent[chainLeader[chainNumber[i]]];
  }

  st[chainNumber[i]]->Update(chainPosition[k], chainPosition[i], x);
}

void Update(int i, int j, int x){
  int k = LCA(i, j);
  UpdateToAncestor(i, k, x);
  UpdateToAncestor(j, k, x);
}

void Solve(){
  int n;
  scanf("%d", &n);

  Reset(n);

  for(int i = 1; i <= n; ++i){
    scanf("%d", &a[i]);
  }

  for(int e = 1; e < n; ++e){
    int i, j;
    scanf("%d%d", &i, &j);
    adj[i].push_back(j);
    adj[j].push_back(i);
  }

  DFS(1, 0);
  PreProcess(n);

  int q;
  scanf("%d", &q);

  while(q--){
    int t, i, j;
    scanf("%d%d%d", &t, &i, &j);

    if(t == 1){
      printf("%d\n", max(0, Query(i, j)));
    }
    else{
      int x;
      scanf("%d", &x);
      Update(i, j, x);
    }
  }
}

int main(){
  int t = 1;
  while(t--){
    Solve();
  }
  return 0;
}