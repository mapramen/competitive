#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define MOD 1000000007

vector< vector< vector<int> > > dp;

int main(){
  int n, m, k, ans = 0;

  cin >> m >> n >> k;

  if(m > n){
    printf("0\n");
    return 0;
  }

  dp.resize(n + 1);
  for(int x = 0; x <= n; ++x)
    dp[x].resize(m + 1, vector<int>(m + 1, 0));

  dp[0][0][0] = 1;

  for(int x = 1; x <= n; ++x){
    for(int i = 1; i <= m; ++i){
      for(int j = 0; j <= i; ++j){
        if(x != k){
          dp[x][i][j] = (dp[x][i][j] + dp[x - 1][i][j]) % MOD;

          if(j < m)
            dp[x][i][j] = (dp[x][i][j] + dp[x - 1][i][j + 1]) % MOD;
        }

        if(j)
          dp[x][i][j] = (dp[x][i][j] + dp[x - 1][i - 1][j - 1]) % MOD;

        dp[x][i][j] = (dp[x][i][j] + dp[x - 1][i - 1][j]) % MOD;
      }
    }

    if(x < k)
      dp[x][0][0] = 1;
  }

  ans = dp[n][m][0];

  for(int i = 1; i <= m; i++)
    ans = (1ll * i * ans) % MOD;

  printf("%d\n", ans);

  return 0;
}
