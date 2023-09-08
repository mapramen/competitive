#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int, int>
#define pll pair<ll, ll>
#define N 4001
#define MOD 998244353

int dp[N];

int main() {
  int n, k;
  scanf("%d%d", &n, &k);

  int ans = 0;

  dp[0] = 1;
  for (int i = 1; i <= n; ++i) {
    int ansx = dp[k - 1];
    for (int j = k - 1, s = 0; j > 0; --j) {
      s = (s + dp[j]) % MOD;
      dp[j] = (s + 1ll * (k - (j - 1)) * dp[j - 1]) % MOD;
    }

    ans = (1ll * k * ans + ansx) % MOD;
    dp[0] = ansx;
  }

  printf("%d\n", ans);

  return 0;
}