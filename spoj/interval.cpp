#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>  // Common file
#include <ext/pb_ds/tree_policy.hpp>      // Including tree_order_statistics_node_update

using namespace std;
using namespace __gnu_pbds;

typedef long long ll;

typedef tree<
    int,
    null_type,
    less<int>,
    rb_tree_tag,
    tree_order_statistics_node_update>
    ordered_set;

ordered_set S;

int GetCount(int x) {
  return x - S.order_of_key(x + 1);
}

int GetCount(int l, int r) {
  return GetCount(r) - GetCount(l - 1);
}

int Solve() {
  int n;
  scanf("%d", &n);

  vector<tuple<int, int, int>> a;

  while (n--) {
    int l, r, c;
    scanf("%d%d%d", &l, &r, &c);
    a.push_back({r, l, c});
  }
  sort(a.begin(), a.end());

  S.clear();

  for (auto [r, _, __] : a) {
    for (int x = S.empty() ? 1 : *S.rbegin() + 1; x <= r; ++x) {
      S.insert(x);
    }
  }

  int ans = 0;
  for (auto [r, l, c] : a) {
    c -= min(c, GetCount(l, r));

    while (c > 0) {
      auto it = prev(S.upper_bound(r));
      S.erase(it);
      ++ans, --c;
    }
  }

  return ans;
}

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    printf("%d\n", Solve());
  }
  return 0;
}