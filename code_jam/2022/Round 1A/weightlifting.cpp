#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 101

int a[N][N], b[N], c[N][N], dp[N][N];

int Solve(){
  int n, m;
  scanf("%d%d", &n, &m);

  for(int i = 1; i <= n; ++i){
    for(int j = 1; j <= m; ++j){
      scanf("%d", &a[i][j]);
    }
  }

  for(int i = 1; i <= n; ++i){
    for(int x = 1; x <= m; ++x){
      b[x] = INT_MAX;
    }

    for(int j = i; j <= n; ++j){
      int s = 0;
      for(int x = 1; x <= m; ++x){
        b[x] = min(b[x], a[j][x]);
        s += b[x];
      }
      c[i][j] = 2 * s;
    }
  }

  for(int i = 1; i <= n; ++i){
    dp[i][i] = c[i][i];
  }

  for(int len = 2; len <= n; ++len){
    for(int i = 1, j = len; j <= n; ++i, ++j){
      int ans = INT_MAX;
      for(int k = i; k < j; ++k){
        ans = min(ans, dp[i][k] + dp[k + 1][j] - c[i][j]);
      }
      dp[i][j] = ans;
    }
  }

  return dp[1][n];
}

int main(){
  int t;
  scanf("%d", &t);
  for(int k = 1; k <= t; ++k){
    printf("Case #%d: %d\n", k, Solve());
  }
  return 0;
}