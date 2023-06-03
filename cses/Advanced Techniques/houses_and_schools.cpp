#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int, int>
#define pll pair<ll, ll>
#define N 3001

int a[N];
ll cost[N][N], dp[N][N];

void DivideAndConquer(int k, int l, int r, int optl, int optr) {
  if (l > r) {
    return;
  }

  int mid = (l + r) / 2, optm = -1;
  ll ans = LLONG_MAX;

  for (int i = optl; i <= min(mid, optr); ++i) {
    ll ansx = dp[k - 1][i - 1] + cost[i][mid];
    if (ansx < ans) {
      ans = ansx, optm = i;
    }
  }

  dp[k][mid] = ans;
  DivideAndConquer(k, l, mid - 1, optl, optm);
  DivideAndConquer(k, mid + 1, r, optm, optr);
}

int main() {
  int n, m;
  scanf("%d%d", &n, &m);

  for (int i = 1; i <= n; ++i) {
    scanf("%d", &a[i]);
  }

  for (int i = 1; i <= n; ++i) {
    ll sk = 0, sj = 0, ans = 0;
    for (int j = i, k = i - 1; j <= n; ++j) {
      sj += a[j];
      ans += 1ll * a[j] * (j - k);

      while (2 * sk < sj) {
        ++k;
        ans += (sk - (sj - sk));
        sk += a[k];
      }

      cost[i][j] = ans;
    }
  }

  for (int i = 1; i <= n; ++i) {
    dp[0][i] = LLONG_MAX / 2;
  }

  for (int k = 1; k <= m; ++k) {
    DivideAndConquer(k, 1, n, 1, n);
  }

  printf("%lld\n", dp[m][n]);

  return 0;
}