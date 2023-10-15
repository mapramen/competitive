#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int, int>
#define pll pair<ll, ll>

bool Solve() {
  ll a, b, p, q;
  scanf("%lld%lld%lld%lld", &a, &b, &p, &q);

  if (a < b) {
    swap(a, b);
  }

  if (p < q) {
    swap(p, q);
  }

  return (p <= a && q <= b) || (p > a && q <= b && pow(1.0 * (a + b) / (p + q), 2) + pow(1.0 * (a - b) / (p - q), 2) >= 2);
}

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    printf("%s\n", Solve() ? "Escape is possible." : "Box cannot be dropped.");
  }
  return 0;
}