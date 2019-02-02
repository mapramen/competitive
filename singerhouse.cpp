#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 401
#define MOD 1000000007

int dp[N][N];

int main(){
  dp[1][0] = dp[1][1] = 1;

  for(int i = 1; i < N - 1; i++){
    for(int l = 0; l < N; l++){
      if(dp[i][l] == 0)
        continue;

      for(int r = 0; r < N && l + r < N; r++){
        if(dp[i][r] == 0)
          continue;

        int k = l + r;
        ll val = (1ll * dp[i][l] * dp[i][r]) % MOD;

        if(k < N - 1)
          dp[i + 1][k + 1] = (dp[i + 1][k + 1] + val) % MOD;

        dp[i + 1][k] = (dp[i + 1][k] + (l + l + r + r + 1) * val) % MOD;

        if(k > 0)
          dp[i + 1][k - 1] = (dp[i + 1][k - 1] + k * (k - 1) * val) % MOD;
      }
    }
  }

  int n;
  cin >> n;
  cout << dp[n][1] << '\n';

  return 0;
}
