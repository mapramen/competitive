#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 100001
#define M 201
#define MOD 998244353

int dp[N][M][2], s[M][2];

int main(){
  int n;

  scanf("%d", &n);

  dp[0][0][1] = 1;

  for(int i = 1; i <= n; ++i){
    int x;
    scanf("%d", &x);

    for(int j = 0; j < M; ++j){
      for(int k = 0; k < 2; ++k){
        s[j][k] = ((j > 0 ? s[j - 1][k] : 0) + dp[i - 1][j][k]) % MOD;
      }
    }

    for(int l = x != -1 ? x : 1, r = x != -1 ? x : M - 1, j = l; j <= r; ++j){
      dp[i][j][0] = (s[j - 1][0] + s[j - 1][1]) % MOD;
      dp[i][j][1] = (0ll + MOD + s[M - 1][1] - s[j - 1][1] + dp[i - 1][j][0]) % MOD;
    }
  }

  int ans = 0;
  for(int j = 1; j < M; ++j){
    ans = (ans + dp[n][j][1]) % MOD;
  }

  printf("%d\n", ans);

  return 0;
}
