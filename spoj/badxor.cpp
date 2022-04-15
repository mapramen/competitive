#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 1001
#define M (1 << 10)
#define MOD 100000007

int dp[N][M];

int Solve(){
  int n, m;
  scanf("%d%d", &n, &m);

  dp[0][0] = 1;

  for(int i = 1; i <= n; ++i){
    int x;
    scanf("%d", &x);

    for(int y = 0; y < M; ++y){
      dp[i][y] = (dp[i - 1][y] + dp[i - 1][y ^ x]) % MOD;
    }
  }

  int ans = 0;
  for(int y = 0; y < M; ++y){
    ans = (ans + dp[n][y]) % MOD;
  }

  for(int j = 1; j <= m; ++j){
    int x;
    scanf("%d", &x);

    ans = (ans - dp[n][x]) % MOD;
    dp[n][x] = 0;
  }

  return (MOD + ans) % MOD;
}

int main(){
  int t;
  scanf("%d", &t);
  for(int k = 1; k <= t; ++k){
    printf("Case %d: %d\n", k, Solve());
  }
  return 0;
}