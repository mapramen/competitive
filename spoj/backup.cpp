#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int, int>
#define pll pair<ll, ll>

int Solve() {
  int n, k;
  scanf("%d%d", &n, &k);

  vector<int> a(n + 2);
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &a[i]);
  }

  vector<bool> used(n + 2);
  used[0] = used[n + 1] = true;

  set<tuple<int, int, int>> S;
  priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> Q;
  for (int i = 2; i <= n; ++i) {
    S.insert({i - 1, i, a[i] - a[i - 1]});
    Q.push({a[i] - a[i - 1], i - 1, i});
  }

  int ans = 0;
  while (!Q.empty() && k > 0) {
    auto [d, l, r] = Q.top();
    Q.pop();

    S.erase({l, r, d});

    if (used[l] || used[r]) {
      continue;
    }

    ans += d;
    --k;

    used[l] = used[r] = true;

    auto it = S.lower_bound({l, 0, 0});
    if (it == S.begin() || it == S.end()) {
      continue;
    }

    auto [l1, r1, d1] = *prev(it);
    auto [l2, r2, d2] = *it;

    S.erase({l1, r1, d1});
    S.erase({l2, r2, d2});

    S.insert({l1, r2, d1 + d2 - d});
    Q.push({d1 + d2 - d, l1, r2});
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