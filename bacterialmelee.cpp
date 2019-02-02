#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 5001
#define B 27
#define MOD 1000000007

int dp[B][N], c[N][N];

int main(){
  int n, ans;
  string s;

  cin >> n >> s;

  dp[0][0] = 1;
  for(auto c : s){
    int i = c - 'a' + 1;
    for(int j = 0; j <= n; j++)
      dp[0][j] = (dp[0][j] - dp[i][j] + MOD) % MOD;

    for(int j = 1; j <= n; j++)
      dp[i][j] = dp[0][j - 1];

    for(int j = 0; j <= n; j++)
      dp[0][j] = (dp[0][j] + dp[i][j]) % MOD;
  }

  c[0][0] = 1;
  for(int i = 1; i <= n; i++){
    c[i][0] = 1;
    for(int j = 1; j <= i; j++)
      c[i][j] = (c[i - 1][j - 1] + c[i - 1][j]) % MOD;
  }

  ans = 0;
  for(int i = 1; i <= n; i++){
    int ansx = (1ll * dp[0][i] * c[n - 1][i - 1]) % MOD;
    ans = (ans + ansx) % MOD;
  }

  cout << ans << '\n';

  return 0;
}
