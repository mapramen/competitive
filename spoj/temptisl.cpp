#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int, int>
#define pll pair<ll, ll>

map<tuple<int, int, int, int>, ll> dp;

ll DP(int n, int a, int k, int i) {
  if (k < 0) {
    return 0;
  }

  if (k == 0) {
    return i == a;
  }

  if (dp.count({n, a, k, i})) {
    return dp[{n, a, k, i}];
  }

  ll ans = DP(n, a, k - 1, (i + 1) % n) + DP(n, a, k - 1, (i - 1 + n) % n);
  dp[{n, a, k, i}] = ans;

  return ans;
}

ll Solve() {
  int n, k;
  scanf("%d%d", &n, &k);

  if (n == -1) {
    exit(0);
  }

  int a, b;
  scanf("%d%d", &a, &b);
  b = abs(b - a);
  b = min(b, n - b);

  return DP(n, b, k, 0);
}

int main() {
  while (true) {
    printf("%lld\n", Solve());
  }
  return 0;
}