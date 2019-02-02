#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 300001
#define LOGN 19

vector< vector< pii > > adj(N);
int a[N];
ll dp[N], dpToRootDetour[N];

//------------------------------------- LCA -------------------------------------//
int start[N], finish[N], t_time[N], indx[N], ind = 0, timer = 0, T[LOGN + 1][2 * N], lg[2 * N];

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

void DFS1(int i, int p){
  start[i] = ++timer;
  t_time[timer] = i;
  indx[i] = ++ind;
  T[0][ind] = start[i];

  for(auto e : adj[i]){
    int k, w;
    tie(k, w) = e;
    if(k == p){
      continue;
    }

    DFS1(k, i);
    dp[i] += max(0ll, dp[k] - 2 * w);

    T[0][++ind] = start[i];
  }

  dp[i] += a[i];

  finish[i] = timer;
}

void DFS2(int i, int p){
  for(auto e : adj[i]){
    int k, w;
    tie(k, w) = e;
    if(k == p){
      continue;
    }

    dpToRootDetour[k] = dpToRootDetour[i] - max(0ll, dp[k] - 2 * w) - w + dp[k];
    dp[k] = max(0ll, dp[i] - max(0ll, dp[k] - 2 * w) - 2 * w) + dp[k];

    DFS2(k, i);
  }
}

int main(){
  int n, q;

  scanf("%d%d", &n, &q);

  for(int i = 1; i <= n; ++i){
    scanf("%d", &a[i]);
  }

  for(int x = 1; x < n; ++x){
    int i, j, w;
    scanf("%d%d%d", &i, &j, &w);
    adj[i].PB(MP(j, w));
    adj[j].PB(MP(i, w));
  }

  DFS1(1, 0);
  DFS2(1, 0);
  BuildLCASparseTable(n);

  while(q--){
    int i, j;
    scanf("%d%d", &i, &j);
    int k = LCA(i, j);
    ll ans = dpToRootDetour[i] + dpToRootDetour[j] - 2 * dpToRootDetour[k] + dp[k];
    printf("%lld\n", ans);
  }

  return 0;
}
