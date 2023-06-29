#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int, int>
#define pll pair<ll, ll>
#define N 200002

int parent[N], cnt[N];

int Find(int i) {
  if (parent[i] != i) {
    return parent[i] = Find(parent[i]);
  }

  if (cnt[i] == 0) {
    return parent[i] = Find(i + 1);
  }

  return i;
}

int main() {
  int n, k, A;
  scanf("%d%d%d", &n, &k, &A);

  vector<tuple<int, int, int>> a;
  for (int i = 1; i <= n; ++i) {
    int x, y, c;
    scanf("%d%d%d", &x, &y, &c);
    a.push_back({k - y, x, c});
  }

  for (int i = 0; i <= k + 1; ++i) {
    parent[i] = i;
    cnt[i] = A;
  }

  sort(a.begin(), a.end());

  ll ans = 0;
  for (auto [y, x, c] : a) {
    for (x = Find(x); x < y && c != 0; x = Find(x + 1)) {
      int ansx = min(c, cnt[x]);
      ans += ansx;
      c -= ansx;
      cnt[x] -= ansx;
    }
  }

  printf("%lld\n", ans);

  return 0;
}