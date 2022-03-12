#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 10001
#define LOGN 13

vector<vector<pii>> adj(N);
int d[N], dis[N], T[LOGN + 1][N];
char op[10];

void Reset(int n){
  for(int i = 0; i <= n; ++i){
    d[i] = 0;
    adj[i].clear();
  }

  for(int k = 0; k <= LOGN; ++k){
    for(int i = 0; i <= n; ++i){
      T[k][i] = 0;
    }
  }
}

void PreProcess(int n){
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

void DFS(int i, int parent, int w){
  T[0][i] = parent;
  d[i] = 1 + d[parent];
  dis[i] = w + dis[parent];

  for(pii& p: adj[i]){
    int j = p.first, w = p.second;
    if(j == parent){
      continue;
    }
    DFS(j, i, w);
  }
}

int Dist(int i, int j){
  int k = LCA(i, j);
  return (dis[i] - dis[k]) + (dis[j] - dis[k]);
}

int KthInPath(int i, int j, int k){
  int lca = LCA(i, j);

  --k;
  int c = d[i] - d[lca], l = c + d[j] - d[lca];
  return k <= c ? KthAncestor(k, i) : KthAncestor(l - k, j);
}

void Solve(){
  int n;
  scanf("%d", &n);

  for(int x = 1; x < n; ++x){
    int i, j, w;
    scanf("%d%d%d", &i, &j, &w);
    adj[i].push_back({j, w});
    adj[j].push_back({i, w});
  }

  DFS(1, 0, 0);
  PreProcess(n);

  while(true){
    scanf("%s", op);

    if(op[1] == 'O'){
      break;
    }

    if(op[0] == 'D'){
      int i, j;
      scanf("%d%d", &i, &j);
      printf("%d\n", Dist(i, j));
    }
    else{
      int i, j, k;
      scanf("%d%d%d", &i, &j, &k);
      printf("%d\n", KthInPath(i, j, k));
    }
  }

  Reset(n);
}

int main(){
  int t;
  scanf("%d", &t);
  for(int k = 1; k <= t; ++k){
    Solve();
  }
  return 0;
}