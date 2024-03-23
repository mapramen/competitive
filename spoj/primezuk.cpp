#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int, int>
#define pll pair<ll, ll>

ll CalculateLargestPrimeDivisor(ll n) {
  ll ans = 1;
  for (ll i = 2; i * i <= n; ++i) {
    if (n % i == 0) {
      ans = i;
      while (n % i == 0) {
        n /= i;
      }
    }
  }
  return max(ans, n);
}

ll Solve() {
  int n;
  scanf("%d", &n);

  ll m = 1;
  while (n--) {
    ll p;
    scanf("%lld", &p);
    m *= p;
  }
  ++m;

  return CalculateLargestPrimeDivisor(m);
}

int main() {
  int t;
  scanf("%d", &t);
  for (int k = 1; k <= t; ++k) {
    printf("Case #%d: %lld\n", k, Solve());
  }
  return 0;
}