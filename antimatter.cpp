#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define BASE 10001
#define B 2
#define MOD 1000000007

int dp[B][2 * BASE];

int main(){
  int n, ans = 0;

  scanf("%d", &n);
  for(int x = 1, cur = 0; x <= n; x++, cur = 1 - cur){
    int j, nxt = 1 - cur;
    memset(dp[nxt], 0, sizeof(dp[nxt]));

    scanf("%d", &j);

    dp[cur][BASE] = (dp[cur][BASE] + 1) % MOD;
    for(int i = 0; i < 2 * BASE; i++){
      if(dp[cur][i] == 0)
        continue;
      dp[nxt][i + j] = (dp[nxt][i + j] + dp[cur][i]) % MOD;
      dp[nxt][i - j] = (dp[nxt][i - j] + dp[cur][i]) % MOD;
    }

    ans = (ans + dp[nxt][BASE]) % MOD;
  }

  printf("%d\n", ans);

  return 0;
}
