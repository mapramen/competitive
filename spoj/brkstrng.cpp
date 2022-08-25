#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 1002
#define INF 1E9

int c[N][N], opt[N][N];
ll dp[N][N];

ll Solve(){
  int m, n;
  if(scanf("%d%d", &m, &n) == EOF){
    exit(0);
  }

  for(int i = 1; i <= n; ++i){
    scanf("%d", &c[i][i]);
  }
  ++n;
  c[n][n] = m;

  for(int i = n; i > 0; --i){
    c[i][i] -= c[i - 1][i - 1];
  }

  for(int k = 2; k <= n; ++k){
    for(int i = 1, j = k; j <= n; ++i, ++j){
      c[i][j] = c[i][j - 1] + c[j][j];
    }
  }

  for(int i = 0; i <= n; ++i){
    for(int j = 0; j <= n; ++j){
      dp[i][j] = INF;
    }
    opt[i][i] = i, dp[i][i] = 0;
  }

  for(int i = n; i > 0; --i){
    for(int j = i + 1; j <= n; ++j){
      ll dpx = LLONG_MAX;
      int optx = n + 1;
      for(int k = opt[i][j - 1]; k <= min(j, opt[i + 1][j]); ++k){
        ll ans = dp[i][k - 1] + dp[k][j];
        if(ans < dpx){
          dpx = ans, optx = k;
        }
      }
      dp[i][j] = dpx + c[i][j], opt[i][j] = optx;
    }
  }

  return dp[1][n];
}

int main(){
  while(true){
    printf("%lld\n", Solve());
  }
  return 0;
}