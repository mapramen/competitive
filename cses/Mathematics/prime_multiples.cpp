#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int, int>
#define pll pair<ll, ll>

ll GetCount(vector<ll>& primes, ll n, int mask) {
  ll ans = n;
  for (int i = 0; i < primes.size(); ++i) {
    if ((mask & (1 << i)) != 0) {
      ans /= primes[i];
    }
  }
  return ans;
}

int main() {
  ll m;
  int n;
  scanf("%lld%d", &m, &n);

  vector<ll> a(n);
  for (ll& x : a) {
    scanf("%lld", &x);
  }

  ll ans = 0;
  for (int mask = 1; mask < (1 << n); ++mask) {
    ll cnt = GetCount(a, m, mask);
    ans += __builtin_popcount(mask) % 2 == 1 ? cnt : -cnt;
  }

  printf("%lld\n", ans);

  return 0;
}