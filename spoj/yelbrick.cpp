#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int, int>
#define pll pair<ll, ll>

ll Solve() {
  int n;
  scanf("%d", &n);

  if (n == 0) {
    exit(0);
  }

  vector<tuple<int, int, int>> a;

  int g = 0;
  for (int i = 0; i < n; i++) {
    int x, y, z;
    scanf("%d%d%d", &x, &y, &z);

    g = __gcd(g, x);
    g = __gcd(g, y);
    g = __gcd(g, z);

    a.push_back({x, y, z});
  }

  ll ans = 0;
  for (auto [x, y, z] : a) {
    ans += (x / g) * (y / g) * (z / g);
  }

  return ans;
}

int main() {
  while (true) {
    printf("%lld\n", Solve());
  }
  return 0;
}