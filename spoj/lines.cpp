#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int, int>
#define pll pair<ll, ll>

pii CalculateSlope(pii& a, pii& b) {
  auto [x1, y1] = a;
  auto [x2, y2] = b;

  int dx = x2 - x1;
  int dy = y2 - y1;

  if (dx == 0) {
    return {0, 1};
  }

  if (dy == 0) {
    return {1, 0};
  }

  int g = __gcd(dx, dy);
  dx /= g;
  dy /= g;

  if (dx < 0) {
    dx *= -1;
    dy *= -1;
  }

  return {dx, dy};
}

int Solve() {
  int n;
  scanf("%d", &n);

  if (n == 0) {
    exit(0);
  }

  vector<pii> pts(n);
  for (pii& pt : pts) {
    scanf("%d%d", &pt.first, &pt.second);
  }

  vector<pii> slopes;
  for (int i = 0; i < n; ++i) {
    for (int j = i + 1; j < n; ++j) {
      slopes.push_back(CalculateSlope(pts[i], pts[j]));
    }
  }

  sort(slopes.begin(), slopes.end());
  slopes.erase(unique(slopes.begin(), slopes.end()), slopes.end());

  return slopes.size();
}

int main() {
  while (true) {
    printf("%d\n", Solve());
  }
  return 0;
}