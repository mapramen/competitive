#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int, int>
#define pll pair<ll, ll>

ll Solve() {
  ll x, y;
  scanf("%lld%lld", &x, &y);

  ll g = __gcd(x, y);
  x /= g, y /= g;

  if (x > y) {
    return 1;
  }

  if (x == y) {
    return -1;
  }

  ll z = y - x;
  return 2 * (y / z) - (y % z == 0);
}

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    printf("%lld\n", Solve());
  }
  return 0;
}