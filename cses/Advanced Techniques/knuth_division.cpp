#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int, int>
#define pll pair<ll, ll>
#define N 5001

ll a[N], pos[N][N], dp[N][N];

ll Sum(int i, int j) {
  return a[j] - a[i - 1];
}

int main() {
  int n;
  scanf("%d", &n);

  for (int i = 1; i <= n; ++i) {
    scanf("%lld", &a[i]);
  }

  for (int i = 1; i <= n; ++i) {
    a[i] += a[i - 1];
  }

  for (int i = 1; i <= n; ++i) {
    pos[i][i] = i, dp[i][i] = 0;
  }

  for (int len = 2; len <= n; ++len) {
    for (int i = 1, j = len; j <= n; ++i, ++j) {
      ll ans = 1e18, opt = -1;
      for (int k = pos[i][j - 1]; k <= pos[i + 1][j]; ++k) {
        ll ansx = dp[i][k] + dp[k + 1][j] + Sum(i, j);
        if (ansx < ans) {
          ans = ansx;
          opt = k;
        }
      }
      dp[i][j] = ans;
      pos[i][j] = opt;
    }
  }

  printf("%lld\n", dp[1][n]);

  return 0;
}