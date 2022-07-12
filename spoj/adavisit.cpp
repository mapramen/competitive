#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 400001
#define LOGN 18

vector<vector<int>> adj(N);
int parent[N], d[N], T[LOGN + 1][N], c[N];

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

void LCADFS(int i, int p){
  parent[i] = p;
  d[i] = 1 + d[p];

  for(int j: adj[i]){
    if(j == p){
      continue;
    }
    LCADFS(j, i);
  }
}

void PreProcess(int n){
  LCADFS(1, 0);

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

  return parent[i];
}

int CollectDFS(int i, int p){
  for(int j: adj[i]){
    if(j == p){
      continue;
    }
    c[i] += CollectDFS(j, i);
  }
  return c[i];
}

void Solve(){
  int n;
  scanf("%d", &n);

  if(n == 1){
    printf("1\n");
    return;
  }

  for(int e = 1; e < n; ++e){
    int i, j;
    scanf("%d%d", &i, &j);
    adj[i].push_back(j);
    adj[j].push_back(i);
  }

  PreProcess(n);

  for(int i = 2; i <= n; ++i){
    int k = LCA(i - 1, i);
    ++c[i - 1], ++c[i];
    --c[k], --c[parent[k]];
  }

  CollectDFS(1, 0);

  for(int i = 1; i <= n; ++i){
    printf("%d\n", c[i]);
  }

  Reset(n);
}

int main(){
  int t = 1;
  while(t--){
    Solve();
  }
  return 0;
}