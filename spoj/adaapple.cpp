#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define tiii tuple<int,int,int>
#define N 300001
#define LOGN 18

class Node{
  public:
  Node(int _l, int _r){
    l = _l, r = _r, val = 0;

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
    val = leftChild->val + rightChild->val;
  }

  int Query(int ql, int qr){
    if(qr < ql || qr < l || r < ql){
      return 0;
    }

    if(ql <= l && r <= qr){
      return val;
    }

    return leftChild->Query(ql, qr) + rightChild->Query(ql, qr);
  }

  private:
  int l;
  int r;
  int val;

  Node* leftChild;
  Node* rightChild;
};

char s[N];
vector<vector<int>> adj(N), chains(N);
int parent[N], d[N], colored[N], subtreeSize[N], chainNumber[N], chainLeader[N], chainPosition[N], T[LOGN + 1][N], timer = 0;
Node* st[N];

void Reset(int n){
  for(int i = 0; i <= n; ++i){
    adj[i].clear();
    chains[i].clear();
    chainNumber[i] = i;
    colored[i] = 0;
  }

  timer = 0;
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

void PreProcess(int n){
  DFS(1, 0);

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
    colored[i] = s[i - 1] - '0';
    st[chainNumber[i]]->Update(chainPosition[i], colored[i]);
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

void Update(int i){
  colored[i] = 1 - colored[i];
  st[chainNumber[i]]->Update(chainPosition[i], colored[i]);
}

int QueryToAncestor(int i, int k){
  int ans = 0;

  while(chainNumber[i] != chainNumber[k]){
    ans += st[chainNumber[i]]->Query(1, chainPosition[i]);
    i = parent[chainLeader[chainNumber[i]]];
  }

  return ans + st[chainNumber[i]]->Query(chainPosition[k], chainPosition[i]);
}

bool Query(int i, int j){
  int k = LCA(i, j);
  int dis = d[i] + d[j] - 2 * d[k] + 1;
  int cnt = QueryToAncestor(i, k) + QueryToAncestor(j, k) - colored[k];
  return cnt == 0 || cnt == dis;
}

int main(){
  int n, q;
  scanf("%d%d%s", &n, &q, s);

  Reset(n);

  for(int e = 1; e < n; ++e){
    int i, j;
    scanf("%d%d", &i, &j);
    ++i, ++j;

    adj[i].push_back(j);
    adj[j].push_back(i);
  }

  PreProcess(n);

  while(q--){
    int t, i;
    scanf("%d%d", &t, &i);
    ++i;
    
    if(t == 0){
      Update(i);
    }
    else{
      int j;
      scanf("%d", &j);
      ++j;

      printf("%s\n", Query(i, j) ? "YES" : "NO");
    }
  }

  return 0;
}