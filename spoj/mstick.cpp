#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int, int>
#define pll pair<ll, ll>

int Solve() {
  int n;
  scanf("%d", &n);

  vector<pii> a(n);
  for (pii& p : a) {
    scanf("%d%d", &p.first, &p.second);
  }
  sort(a.begin(), a.end());

  set<pii> S;
  for (int i = 0; i < n; ++i) {
    auto it = S.upper_bound({a[i].second, i});
    if (it != S.begin()) {
      it = prev(it);
      S.erase(it);
    }
    S.insert({a[i].second, i});
  }

  return S.size();
}

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    printf("%d\n", Solve());
  }
  return 0;
}