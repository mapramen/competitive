#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int, int>
#define pll pair<ll, ll>

pll Solve(ll n) {
  if (n == 1) {
    return {1, 1};
  }

  auto [p, q] = Solve(n / 2);

  if (n % 2 == 0) {
    q += p;
  } else {
    p += q;
  }

  ll g = __gcd(p, q);
  p /= g, q /= g;

  return {p, q};
}

pll Solve() {
  ll n;
  scanf("%lld", &n);

  if (n == 0) {
    exit(0);
  }

  return Solve(n);
}

int main() {
  while (true) {
    auto [p, q] = Solve();
    printf("%lld/%lld\n", p, q);
  }
  return 0;
}