#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int, int>
#define pll pair<ll, ll>
#define N 502
#define MOD 1000000007
#define INV2 500000004

int a[N];
int dp[N][N];

int main() {
  int n, m;
  scanf("%d%d", &n, &m);

  for (int i = 1; i <= n; ++i) {
    scanf("%d", &a[i]);
  }
  a[n + 1] = m + 1;

  for (int i = 1; i <= m; ++i) {
    dp[i][m + 1] = m - i + 1;
  }

  for (int i = m; i > 0; --i) {
    for (int j = m; j > i; --j) {
      dp[i][j] = (1ll * (dp[i + 1][j] + 1 + dp[i][j + 1]) * INV2) % MOD;
    }
  }

  int ans = 0;
  for (int i = 1; i <= n; ++i) {
    ans = (ans + dp[a[i]][a[i + 1]]) % MOD;
  }

  printf("%d\n", ans);

  return 0;
}