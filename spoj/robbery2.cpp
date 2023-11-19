#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int, int>
#define pll pair<ll, ll>

vector<ll> Solve() {
  ll n;
  int k;
  scanf("%lld%d", &n, &k);

  ll x = max(0.0, (-1 + sqrt(1 + 8 * n)) / 2 - 1);
  while (x * (x + 1) / 2 <= n) {
    ++x;
  }
  --x;

  x /= k;

  vector<ll> ans(k);
  for (int i = 1; i <= k; ++i) {
    ans[i - 1] = x * i + x * (x - 1) / 2 * k;
  }

  n -= x * k * (x * k + 1) / 2;
  for (int i = 1; i <= k && n > 0; ++i) {
    ll z = min(n, x * k + i);
    ans[i - 1] += z;
    n -= z;
  }

  return ans;
}

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    for (ll x : Solve()) {
      printf("%lld ", x);
    }
    printf("\n");
  }
  return 0;
}