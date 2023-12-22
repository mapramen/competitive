#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int, int>
#define pll pair<ll, ll>
#define B 60

int main() {
  int n;
  scanf("%d", &n);

  vector<int> cnt(B);
  for (int i = 1; i <= n; ++i) {
    ll x;
    scanf("%lld", &x);
    for (int k = 0; k < B; ++k) {
      cnt[k] += ((x & (1ll << k)) != 0);
    }
  }

  ll ans = 0;
  for (int k = 0; k < B; ++k) {
    if (cnt[k] == 0 || cnt[k] == n) {
      continue;
    }
    ans += (1ll << k);
  }

  printf("%lld\n", ans);

  return 0;
}