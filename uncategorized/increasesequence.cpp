#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 2001
#define MOD 1000000007

int a[N], dp[N][N];

int main(){
  int n, h, ans = 0;

  scanf("%d%d", &n, &h);
  for(int i = 1; i <= n; i++)
    scanf("%d", &a[i]);

  dp[0][0] = 1;

  for(int i = 1; i <= n; i++){
    int j = h - a[i];
    if(j < 0)
      continue;

    dp[i][j] = (dp[i][j] + 1ll * (j + 1) * dp[i - 1][j]) % MOD;

    if(j < N - 1)
      dp[i][j] = (dp[i][j] + 1ll * (j + 1) * dp[i - 1][j + 1]) % MOD;

    if(j)
      dp[i][j] = (dp[i][j] + dp[i - 1][j - 1]) % MOD;
  }

  for(int i = 0; i < 2; i++)
    ans = (ans + dp[n][i]) % MOD;

  printf("%d\n", ans);

  return 0;
}
