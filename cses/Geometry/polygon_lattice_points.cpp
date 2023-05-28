#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int, int>
#define pll pair<ll, ll>

int main() {
  int n;
  scanf("%d", &n);

  vector<pii> p(n);
  for (int i = 0; i < n; i++) {
    scanf("%d%d", &p[i].first, &p[i].second);
  }

  ll area = 0, boundary_points = 0;
  for (int i = 0; i < n; i++) {
    int j = (i + 1) % n;
    area += (ll)p[i].first * p[j].second - (ll)p[i].second * p[j].first;

    int dx = abs(p[i].first - p[j].first), dy = abs(p[i].second - p[j].second);
    boundary_points += __gcd(dx, dy);
  }
  area = abs(area);

  ll interior_points = (area - boundary_points + 2) / 2;

  printf("%lld %lld\n", interior_points, boundary_points);

  return 0;
}