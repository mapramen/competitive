#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int, int>
#define pll pair<ll, ll>
#define N 501

int a[N], dp[N][N];

int main() {
  int n, m, t;
  scanf("%d%d%d", &n, &m, &t);

  for (int i = 1; i <= n; ++i) {
    scanf("%d", &a[i]);
  }

  for (int i = 1; i <= n; ++i) {
    for (int k = 1; k <= m; ++k) {
      dp[i][k] = dp[i - 1][k];
    }

    for (int j = i, x = 1, h = INT_MAX; x <= t && j > 0; --j, ++x) {
      h = min(h, a[j]);
      for (int k = 1; k <= m; ++k) {
        dp[i][k] = max(dp[i][k], h * x + dp[j - 1][k - 1]);
      }
    }
  }

  printf("%d\n", *max_element(dp[n] + 1, dp[n] + m + 1));

  return 0;
}