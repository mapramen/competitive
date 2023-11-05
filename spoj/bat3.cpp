#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int, int>
#define pll pair<ll, ll>
#define N 1001

int a[N], dp[N];

int Solve() {
  int n, m;
  scanf("%d%d", &n, &m);
  ++m;

  for (int i = 1; i <= n; ++i) {
    scanf("%d", &a[i]);
  }

  for (int i = 1; i <= n; ++i) {
    int ans = 0;
    for (int j = 1; j < i; ++j) {
      if (j == m || a[j] > a[i]) {
        ans = max(ans, dp[j]);
      }
    }
    dp[i] = ans + 1;
  }

  return *max_element(dp + 1, dp + n + 1);
}

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    printf("%d\n", Solve());
  }
  return 0;
}