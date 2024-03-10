#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int, int>
#define pll pair<ll, ll>

void InsertInterval(map<pii, int>& dp, int l, int r, int val) {
  if (l > r) {
    return;
  }
  dp[{l, r}] = val;
}

void Solve() {
  int n;
  scanf("%d", &n);

  map<pii, int> dp;
  InsertInterval(dp, 1, n, 0);

  ll ans = 0;
  while (n--) {
    int x;
    scanf("%d", &x);

    auto it = prev(dp.upper_bound({x, INT_MAX}));
    auto [l, r] = it->first;
    int val = it->second;

    dp.erase(it);

    InsertInterval(dp, l, x - 1, val + 1);
    InsertInterval(dp, x + 1, r, val + 1);

    ans += val;
    printf("%lld\n", ans);
  }
}

int main() {
  int t = 1;
  while (t--) {
    Solve();
  }
  return 0;
}