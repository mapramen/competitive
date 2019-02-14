#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 1001
#define B 4
#define MOD 998244353

int c[B][B], dp[N][2 * N][B];

int main(){
  int n, m;

  cin >> n >> m;

  for(int j = 1; j < B; ++j){
    c[0][j] = 1;
  }

  c[1][2] = 2;
  c[2][1] = 2;

  for(int j = 0; j < B - 1; ++j){
    c[B - 1][j] = 1;
  }

  dp[1][1][0] = dp[1][1][B - 1] = 1;
  dp[1][2][1] = dp[1][2][2] = 1;

  for(int i = 1; i < n; ++i){
    for(int k = 0; k <= m; ++k){
      for(int j = 0; j < B; ++j){
        if(dp[i][k][j] == 0){
          continue;
        }
        for(int nj = 0; nj < B; ++nj){
          int nk = k + c[j][nj];
          if(k > m){
            continue;
          }
          dp[i + 1][nk][nj] = (dp[i + 1][nk][nj] + dp[i][k][j]) % MOD;
        }
      }
    }
  }

  int ans = 0;
  for(int j = 0; j < B; ++j){
    ans = (ans + dp[n][m][j]) % MOD;
  }

  cout << ans << '\n';

  return 0;
}
