#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 201
#define MOD 1000000007

int dp[N][N];

int Solve(){
  int n, m;
  scanf("%d%d", &n, &m);

  for(int i = 0; i <= n; ++i){
    for(int j = 1; j <= m; ++j){
      dp[i][j] = 0;
    }
  }

  dp[0][0] = 1;
  for(int i = 1; i <= n; ++i){
    int l, r;
    scanf("%d%d", &l, &r);

    for(int j = 1; j <= m; ++j){
      dp[i - 1][j] = (dp[i - 1][j] + dp[i - 1][j - 1]) % MOD;
    }

    for(int j = l; j <= m; ++j){
      dp[i][j] = dp[i - 1][j - l];
    }

    for(int j = r + 1; j <= m; ++j){
      dp[i][j] = (MOD + dp[i][j] - dp[i - 1][j - r - 1]) % MOD;
    }
  }

  return dp[n][m];
}

int main(){
  int t;
  scanf("%d", &t);
  while(t--){
    printf("%d\n", Solve());
  }
  return 0;
}