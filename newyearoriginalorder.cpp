#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 705
#define B 10
#define MOD 1000000007

char s[N];
int a[N];
ll dp[2][N][B], c[2][N][B];

int main(){
  int n;

  scanf("%s", s);
  n = strlen(s);

  for(int i = 1; i <= n; ++i)
    a[i] = s[i - 1] - '0';

  for(int i = 0; i < B; ++i)
    c[1][0][i] = 1;

  for(int i = 1; i <= n; ++i){
    for(int j = 0; j < B; ++j){
      for(int k = 0; k < B; ++k){
        if(k > j)
          dp[0][i][k] = (dp[0][i][k] + dp[0][i - 1][k]) % MOD;
        else
          dp[0][i][k] = (dp[0][i][k] + 10 * dp[0][i - 1][k] + c[0][i - 1][k]) % MOD;
        c[0][i][k] = (c[0][i][k] + c[0][i - 1][k]) % MOD;
      }
    }

    for(int j = 0; j < a[i]; ++j){
      for(int k = 0; k < B; ++k){
        if(k > j)
          dp[0][i][k] = (dp[0][i][k] + dp[1][i - 1][k]) % MOD;
        else
          dp[0][i][k] = (dp[0][i][k] + 10 * dp[1][i - 1][k] + c[1][i - 1][k]) % MOD;
        c[0][i][k] = (c[0][i][k] + c[1][i - 1][k]) % MOD;
      }
    }

    int j = a[i];
    for(int k = 0; k < B; ++k){
      if(k > j)
        dp[1][i][k] = (dp[1][i][k] + dp[1][i - 1][k]) % MOD;
      else
        dp[1][i][k] = (dp[1][i][k] + 10 * dp[1][i - 1][k] + c[1][i - 1][k]) % MOD;
      c[1][i][k] = (c[1][i][k] + c[1][i - 1][k]) % MOD;
    }
  }

  ll ans = 0;
  for(int i = 1; i < B; ++i)
    ans = (ans + dp[0][n][i] + dp[1][n][i]) % MOD;

  printf("%lld\n", ans);

  return 0;
}
