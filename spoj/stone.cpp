#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int, int>
#define pll pair<ll, ll>
#define pdd pair<double, double>

ll Cross(pii p, pii q) {
  return 1ll * p.first * q.second - 1ll * p.second * q.first;
}

pdd Solve() {
  int n;
  scanf("%d", &n);

  vector<pii> pts(n);
  for (pii& pt : pts) {
    scanf("%d%d", &pt.first, &pt.second);
  }

  double area = 0, cx = 0, cy = 0;
  for (int i = 0; i < n; ++i) {
    int j = (i + 1) % n;
    ll a = Cross(pts[i], pts[j]);
    area += a;
    cx += (pts[i].first + pts[j].first) * a;
    cy += (pts[i].second + pts[j].second) * a;
  }

  cx /= (3 * area), cy /= (3 * area);
  return {cx, cy};
}

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    pdd ans = Solve();
    printf("%.2lf %.2lf\n", ans.first, ans.second);
  }
  return 0;
}