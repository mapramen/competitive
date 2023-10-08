#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int, int>
#define pll pair<ll, ll>

pll Solve() {
  ll n;
  scanf("%lld", &n);

  ll m = n;
  while (__builtin_popcountll(m) != 1) {
    m += (m & -m);
  }

  ll ansl = m, ansc = 0;
  while (n != m) {
    m /= 2;
    if (n > m) {
      n -= m;
    }
    ++ansc;
  }

  return {ansl, ansc};
}

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    auto [ansl, ansc] = Solve();
    printf("%lld %lld\n", ansl, ansc);
  }
  return 0;
}