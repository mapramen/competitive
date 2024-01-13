#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int, int>
#define pll pair<ll, ll>

ll Solve() {
  int n, a, b;
  scanf("%d%d%d", &n, &a, &b);

  int x = 0;
  ll beijing_cost = 0, shangai_cost = LLONG_MAX / 2;
  while (n--) {
    int y;
    scanf("%d", &y);
    shangai_cost = b + min(beijing_cost + a, shangai_cost + 1ll * max(0, y - x - 1) * b);
    beijing_cost = shangai_cost + a;
    x = y;
  }

  return beijing_cost;
}

int main() {
  int t;
  scanf("%d", &t);
  for (int k = 1; k <= t; ++k) {
    printf("Case #%d: %lld\n", k, Solve());
  }
  return 0;
}