#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 21
#define M 1001

int batch_costs[N], costs[N][N], ratings[N][N], dp[M], t[M];

int Solve(){
  int n, m, k;
  scanf("%d%d%d", &n, &m, &k);

  for(int i = 1; i <= n; ++i){
    scanf("%d", &batch_costs[i]);
  }

  for(int i = 1; i <= n; ++i){
    for(int j = 1; j <= m; ++j){
      scanf("%d", &costs[i][j]);
    }
  }

  for(int i = 1; i <= n; ++i){
    for(int j = 1; j <= m; ++j){
      scanf("%d", &ratings[i][j]);
    }
  }

  for(int x = 0; x <= k; ++x){
    dp[x] = 0;
  }

  for(int i = 1; i <= n; ++i){
    for(int x = 0; x <= k; ++x){
      t[x] = INT_MIN;
    }

    for(int x = k, y = k - batch_costs[i]; y != -1; --x, --y){
      t[x] = dp[y];
    }

    for(int j = 1; j <= m; ++j){
      for(int x = costs[i][j], y = 0, z = ratings[i][j]; x <= k; ++x, ++y){
        t[x] = max(t[x], t[y] + z);
      }
    }

    for(int x = 0; x <= k; ++x){
      dp[x] = max(dp[x], t[x]);
    }
  }

  return *max_element(dp, dp + k + 1);
}

int main(){
  int t;
  scanf("%d", &t);
  while(t--){
    printf("%d\n", Solve());
  }
  return 0;
}