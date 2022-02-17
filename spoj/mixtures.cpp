#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define MOD 100

int Solve(){
  int n;
  
  if(scanf("%d", &n) == EOF){
    exit(0);
  }

  vector<vector<int>> a(n, vector<int>(n));
  vector<vector<int>> dp(n, vector<int>(n));

  for(int i = 0; i < n; ++i){
    scanf("%d", &a[i][i]);
  }

  for(int len = 2; len <= n; ++len){
    for(int i = 0, j = len - 1; j < n; ++i, ++j){
      int ans = INT_MAX;
      for(int k = i; k < j; ++k){
        ans = min(ans, dp[i][k] + dp[k + 1][j] + a[i][k] * a[k + 1][j]);
      }
      a[i][j] = (a[i][j - 1] + a[j][j]) % MOD;
      dp[i][j] = ans;
    }
  }

  return dp[0][n - 1];
}

int main(){
  while(true){
    printf("%d\n", Solve());
  }
  return 0;
}