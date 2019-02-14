#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 1001
#define LOGN 10

vector< vector<int> > adj(N);

//------------------------------------- LCA -------------------------------------//
int start[N], finish[N], t_time[N], indx[N], ind = 1, timer = 1, T[LOGN + 1][2 * N], lg[2 * N];

void BuildLCASparseTable(int n){
  n = (n << 1);

  for(int i = 2; i < n; i++)
    lg[i] = 1 + lg[i / 2];

  for(int k = 1; (1 << k) < n; k++)
    for(int i = 1, j = 1 + (1 << (k - 1)), m = n - (1 << k) + 1; i < m; i++, j++)
      T[k][i] = min(T[k - 1][i], T[k - 1][j]);
}

int LCA(int x, int y){
  x = indx[x], y = indx[y];

  if(x > y) swap(x,y);

  int k = lg[y - x + 1];
  k = min(T[k][x], T[k][y - (1 << k) + 1]);
  int z = t_time[k];
  return z;
}
//----------------------------------- LCA Ends -----------------------------------//

void DFS(int i){
  start[i] = timer;
  t_time[timer++] = i;
  indx[i] = ind;
  T[0][ind++] = start[i];

  for(auto k : adj[i]){
    DFS(k);
    T[0][ind++] = start[i];
  }

  finish[i] = timer;
}

int main(){
  int t;
  scanf("%d", &t);
  for(int k = 1; k <= t; k++){
    int n, q;
    scanf("%d", &n);
    for(int i = 1; i <= n; i++){
      int l;
      scanf("%d", &l);
      while(l--){
        int j;
        scanf("%d", &j);
        adj[i].PB(j);
      }
    }
    DFS(1);
    BuildLCASparseTable(n);
    scanf("%d", &q);
    printf("Case %d:\n", k);
    while(q--){
      int i, j;
      scanf("%d%d", &i, &j);
      printf("%d\n", LCA(i, j));
    }
    for(int i = 1; i <= n; i++)
      adj[i].clear();
    ind = 1, timer = 1;
  }

  return 0;
}
