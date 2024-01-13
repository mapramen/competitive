#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int, int>
#define pll pair<ll, ll>

void Solve() {
  ll n, a, b;
  scanf("%lld%lld%lld", &n, &a, &b);

  for (ll g = __gcd(a, b); g > 0; --g) {
    printf("%lld", n);
  }
  printf("\n");
}

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    Solve();
  }
  return 0;
}