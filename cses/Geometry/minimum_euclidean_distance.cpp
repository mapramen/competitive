#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int, int>
#define pll pair<ll, ll>

ll Dis2(pii a, pii b) {
  int dx = a.first - b.first, dy = a.second - b.second;
  return 1ll * dx * dx + 1ll * dy * dy;
}

int main() {
  int n;
  scanf("%d", &n);

  vector<pii> pts;
  for (int i = 1; i <= n; ++i) {
    int x, y;
    scanf("%d%d", &x, &y);
    pts.push_back({x, y});
  }

  sort(pts.begin(), pts.end());

  set<pll> st;

  ll ans = 8e18;
  for (int i = 0, j = 0; i < n; ++i) {
    while (j < i && 1ll * (pts[i].first - pts[j].first) * (pts[i].first - pts[j].first) > ans) {
      st.erase({pts[j].second, pts[j].first});
      ++j;
    }

    auto it = st.lower_bound({pts[i].second - (ll)sqrt(ans) - 1, pts[i].first});
    while (it != st.end() && 1ll * (it->first - pts[i].second) * (it->first - pts[i].second) <= ans) {
      ans = min(ans, Dis2(pts[i], {it->second, it->first}));
      ++it;
    }

    st.insert({pts[i].second, pts[i].first});
  }

  printf("%lld\n", ans);

  return 0;
}