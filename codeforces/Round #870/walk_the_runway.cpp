#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int, int>
#define pll pair<ll, ll>
#define N 5001

bitset<N> adj[N], T;
vector<vector<int>> V(N);
int cost[N];
ll dp[N];

int main() {
  int m, n;
  scanf("%d%d", &m, &n);

  for (int i = 1; i <= n; ++i) {
    scanf("%d", &cost[i]);
  }

  for (int i = 1; i <= n; ++i) {
    adj[i].set();
  }

  while (m--) {
    for (int r = 1; r <= n; ++r) {
      V[r].clear();
    }

    for (int i = 1; i <= n; ++i) {
      int r;
      scanf("%d", &r);
      V[r].push_back(i);
    }

    T.reset();
    for (int r = 1; r <= n; ++r) {
      for (int i : V[r]) {
        adj[i] &= T;
      }

      for (int i : V[r]) {
        T.set(i);
      }
    }
  }

  vector<int> v(n);
  iota(v.begin(), v.end(), 1);
  sort(v.begin(), v.end(),
       [](int i, int j) { return adj[i].count() < adj[j].count(); });

  for (int i : v) {
    ll ans = 0;
    for (int j = 1; j <= n; ++j) {
      if (!adj[i].test(j)) {
        continue;
      }
      ans = max(ans, dp[j]);
    }
    ans += cost[i];
    dp[i] = ans;
  }

  ll ans = *max_element(dp + 1, dp + n + 1);
  printf("%lld\n", ans);

  return 0;
}