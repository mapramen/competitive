#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define tiii tuple<int,int,int>
#define N 10001
#define LOGN 14

class Node{
  public:
  Node(int _l, int _r){
    l = _l, r = _r, val = INT_MIN;

    if(l == r){
      leftChild = NULL, rightChild = NULL;
    }
    else{
      int mid = (l + r) / 2;
      leftChild = new Node(l, mid), rightChild = new Node(mid + 1, r);
    }
  }

  void Update(int i, int x){
    if(i < l || r < i){
      return;
    }

    if(l == i && r == i){
      val = x;
      return;
    }

    leftChild->Update(i, x), rightChild->Update(i, x);
    val = max(leftChild->val, rightChild->val);
  }

  int Query(int ql, int qr){
    if(qr < ql || qr < l || r < ql){
      return INT_MIN;
    }

    if(ql <= l && r <= qr){
      return val;
    }

    return max(leftChild->Query(ql, qr), rightChild->Query(ql, qr));
  }

  private:
  int l;
  int r;
  int val;

  Node* leftChild;
  Node* rightChild;
};

vector<vector<int>> adj(N), chains(N);
tiii edges[N];
int parent[N], d[N], subtreeSize[N], chainNumber[N], chainLeader[N], chainPosition[N], T[LOGN + 1][N], edgeToVertex[N];
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

void UpdateEdgeWeight(int e, int w){
  int i = edgeToVertex[e];
  st[chainNumber[i]]->Update(chainPosition[i], w);
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

  for(int e = 1; e < n; ++e){
    tiii edge = edges[e];
    int i = get<0>(edge), j = get<1>(edge), w = get<2>(edge);

    if(d[i] > d[j]){
      swap(i, j);
    }

    edgeToVertex[e] = j;
    UpdateEdgeWeight(e, w);
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

int QueryToAncestor(int i, int k){
  int ans = INT_MIN;

  while(chainNumber[i] != chainNumber[k]){
    ans = max(ans, st[chainNumber[i]]->Query(1, chainPosition[i]));
    i = parent[chainLeader[chainNumber[i]]];
  }

  return max(ans, st[chainNumber[i]]->Query(chainPosition[k] + 1, chainPosition[i]));
}

int Query(int i, int j){
  int k = LCA(i, j);
  return max(QueryToAncestor(i, k), QueryToAncestor(j, k));
}

void Solve(){
  int n;
  scanf("%d", &n);

  Reset(n);

  for(int e = 1; e < n; ++e){
    int i, j, w;
    scanf("%d%d%d", &i, &j, &w);
    
    edges[e] = {i, j, w};
    adj[i].push_back(j);
    adj[j].push_back(i);
  }

  DFS(1, 0);
  PreProcess(n);

  char op[20];
  while(true){
    scanf("%s", op);

    if(op[0] == 'D'){
      break;
    }

    int i, j;
    scanf("%d%d", &i, &j);

    if(op[0] == 'C'){
      UpdateEdgeWeight(i, j);
    }
    else{
      printf("%d\n", Query(i, j));
    }
  }
}

int main(){
  int t;
  scanf("%d", &t);
  while(t--){
    Solve();
  }
  return 0;
}