#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 201
#define K 1001
#define MOD 1000000007

int a[N], dp[N][N][K];

int main(){
  int n, k, ans;

  cin >> n >> k;

  for(int i = 1; i <= n; i++)
    cin >> a[i];

  sort(a + 1, a + n + 1);

  dp[1][0][0] = dp[1][1][0] = 1;
  for(int i = 1; i < n; i++){
    for(int j = 0; j <= i; j++){
      for(int x = 0; x <= k; x++){
        int x_new = x + j * (a[i + 1] - a[i]);
        if(dp[i][j][x] == 0 || x_new > k)
          continue;

        dp[i + 1][j][x_new] = (dp[i + 1][j][x_new] + dp[i][j][x]) % MOD;
        dp[i + 1][j + 1][x_new] = (dp[i + 1][j + 1][x_new] + dp[i][j][x]) % MOD;

        if(j){
          dp[i + 1][j - 1][x_new] = (dp[i + 1][j - 1][x_new] + 1ll * j * dp[i][j][x]) % MOD;
          dp[i + 1][j][x_new] = (dp[i + 1][j][x_new] + 1ll * j * dp[i][j][x]) % MOD;
        }
      }
    }
  }

  ans = 0;
  for(int x = 0; x <= k; x++)
    ans = (ans + dp[n][0][x]) % MOD;

  cout << ans << '\n';

  return 0;
}
