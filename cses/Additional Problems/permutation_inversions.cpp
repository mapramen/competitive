#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int, int>
#define pll pair<ll, ll>
#define MOD 1000000007

int main() {
  int n, m;
  scanf("%d%d", &n, &m);

  vector<int> dp(m + 1);

  dp[0] = 1;
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      dp[j] = (dp[j] + dp[j - 1]) % MOD;
    }

    for (int j = m; j >= i; --j) {
      dp[j] = (dp[j] - dp[j - i] + MOD) % MOD;
    }
  }

  printf("%d\n", dp[m]);

  return 0;
}