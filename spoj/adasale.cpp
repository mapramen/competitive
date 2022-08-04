#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 3001

int L[N], P[N];
ll dp[2][N], inf = 1e18;

int main(){
  int n, m, mod;
  scanf("%d%d%d", &n, &m, &mod);

  for(int i = 1; i <= n; ++i){
    scanf("%d", &L[i]);
  }

  for(int i = 1; i <= n; ++i){
    scanf("%d", &P[i]);
  }

  for(int i = 0; i <= n; ++i){
    for(int j = 0; j <= m; ++j){
      dp[0][j] = -inf, dp[1][j] = -inf;
    }
  }

  dp[0][0] = 0;
  for(int i = 1; i <= n; ++i){
    for(int j = 0; j <= m; ++j){
      dp[0][j] = max(dp[0][j], dp[1][j]);
      dp[1][j] = -inf;
    }

    for(int j = m - 1; j != -1; --j){
      dp[1][j] = max(dp[1][j], max(dp[0][j + 1] - L[i], dp[1][j + 1]) + (1ll * i * (j + 1) * P[i]) % mod);
    }

    for(int j = 1; j <= m; ++j){
      dp[1][j] = max(dp[1][j], max(dp[0][j - 1] - L[i], dp[1][j - 1]) - (1ll * i * j * P[i]) % mod);
    }
  }

  ll ans = 0;
  for(int j = 0; j <= m; ++j){
    ans = max(ans, max(dp[0][j], dp[1][j]));
  }

  printf("%lld\n", ans);

  return 0;
}