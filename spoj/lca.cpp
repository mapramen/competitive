#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 1001
#define LOGN 10

vector<vector<int>> adj(N);
int d[N], T[LOGN + 1][N];

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

void DFS(int i){
  for(int j: adj[i]){
    T[0][j] = i;
    d[j] = 1 + d[i];
    DFS(j);
  }
}

void Solve(){
  int n;
  scanf("%d", &n);

  int root = 0;
  for(int i = 1; i <= n; ++i){
    root ^= i;

    int m;
    scanf("%d", &m);

    while(m--){
      int j;
      scanf("%d", &j);
    
      adj[i].push_back(j);
      root ^= j;
    }
  }

  DFS(root);
  PreProcess(n);

  int q;
  scanf("%d", &q);

  while(q--){
    int i, j;
    scanf("%d%d", &i, &j);
    printf("%d\n", LCA(i, j));
  }


  Reset(n);
}

int main(){
  int t;
  scanf("%d", &t);
  for(int k = 1; k <= t; ++k){
    printf("Case %d:\n", k);
    Solve();
  }
  return 0;
}