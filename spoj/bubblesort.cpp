#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>  // Common file
#include <ext/pb_ds/tree_policy.hpp>      // Including tree_order_statistics_node_update

using namespace std;
using namespace __gnu_pbds;

typedef long long ll;

#define pii pair<int, int>
#define pll pair<ll, ll>
#define MOD 10000007

typedef tree<
    pll,
    null_type,
    less<pll>,
    rb_tree_tag,
    tree_order_statistics_node_update>
    ordered_set;

ordered_set S;

ll Solve() {
  int n;
  scanf("%d", &n);

  ll ans = 0;
  for (int i = 0; i < n; ++i) {
    ll x;
    scanf("%lld", &x);

    ans += (i - S.order_of_key({x + 1, 0}));
    S.insert({x, i});
  }

  S.clear();

  return ans % MOD;
}

int main() {
  int t;
  scanf("%d", &t);
  for (int k = 1; k <= t; ++k) {
    printf("Case %d: %lld\n", k, Solve());
  }
  return 0;
}