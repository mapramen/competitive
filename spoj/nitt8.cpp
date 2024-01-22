#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int, int>
#define pll pair<ll, ll>

ll Solve() {
  int n;
  scanf("%d", &n);

  vector<pii> a(n);
  for (int i = 0; i < n; ++i) {
    int x;
    scanf("%d", &x);
    a[i] = {x, i};
  }
  sort(a.begin(), a.end(), greater<pii>());

  ll ans = 0;
  for (int i = 0, mn = n, mx = 0; i < n; ++i) {
    auto [v, k] = a[i];
    mn = min(mn, k);
    mx = max(mx, k);
    ans = max(ans, 1ll * v * max(abs(k - mx), abs(k - mn)));
  }
  return ans;
}

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    printf("%lld\n", Solve());
  }
  return 0;
}