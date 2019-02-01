#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 51

ll c[N][N], dp[N][N][N][N], MOD;

void PreProcess(){
  for(int i = 0; i < N; ++i){
    c[i][0] = 1 % MOD;
    for(int j = 1; j <= i; ++j){
      c[i][j] = (c[i - 1][j - 1] + c[i - 1][j]) % MOD;
    }
  }
}

ll nCr(int n, int r){
  if(n < 0 || r < 0 || n < r){
    return 0ll;
  }
  return c[n][r];
}

int main(){
  int n, m, k;

  cin >> n >> m >> k >> MOD;

  PreProcess();

  dp[0][0][0][0] = 1 % MOD;

  for(int i = 0; i < n; ++i){
    for(int currentK = 0; currentK <= k; ++currentK){
      for(int currentKPos = 0; currentKPos <= i; ++currentKPos){
        for(int currentIntervalsCount = 0; currentIntervalsCount <= m; ++currentIntervalsCount){
          if(dp[i][currentK][currentKPos][currentIntervalsCount] == 0){
            continue;
          }
          for(int intervalsCountDelta = 0, nextIntervalsCount = currentIntervalsCount; nextIntervalsCount <= m; ++intervalsCountDelta, ++nextIntervalsCount){
            dp[i + 1][currentK][currentKPos][nextIntervalsCount] = (dp[i + 1][currentK][currentKPos][nextIntervalsCount] + nCr(currentKPos, intervalsCountDelta) * dp[i][currentK][currentKPos][currentIntervalsCount]) % MOD;
            if(currentK < k){
              dp[i + 1][currentK + 1][i + 1][nextIntervalsCount] = (dp[i + 1][currentK + 1][i + 1][nextIntervalsCount] + (MOD + nCr(i + 1, intervalsCountDelta) - nCr(currentKPos, intervalsCountDelta)) * dp[i][currentK][currentKPos][currentIntervalsCount]) % MOD;
            }
          }
        }
      }
    }
  }

  ll ans = 0;
  for(int currentKPos = 1; currentKPos <= n; ++currentKPos){
    ans = (ans + dp[n][k][currentKPos][m]) % MOD;
  }

  cout << ans << '\n';

  return 0;
}
