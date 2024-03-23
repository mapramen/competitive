#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int, int>
#define pll pair<ll, ll>

string Solve() {
  ll x1, y1, x2, y2;
  scanf("%lld%lld%lld%lld", &x1, &y1, &x2, &y2);

  if (x1 + y1 == 0) {
    return "0";
  }

  ll p = x1 * (x2 + 1) + y1 * (y2 + 1);
  ll q = (x1 + y1) * (x2 + y2 + 1);

  ll g = __gcd(p, q);
  p /= g, q /= g;

  return to_string(p) + "/" + to_string(q);
}

int main() {
  int t;
  scanf("%d", &t);
  for (int k = 1; k <= t; ++k) {
    printf("Case %d: %s\n", k, Solve().c_str());
  }
  return 0;
}