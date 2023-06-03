#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int, int>
#define pll pair<ll, ll>
#define N 200001

int parent[N];
pii edges[N], queries[N], qans_range[N];
vector<vector<int>> query_nos(N);

void Reset(int n) {
  for (int i = 1; i <= n; ++i) {
    parent[i] = i;
  }
}

int Find(int i) {
  return parent[i] == i ? i : parent[i] = Find(parent[i]);
}

void Union(int i, int j) {
  i = Find(i), j = Find(j);
  if (i == j) {
    return;
  }

  if (i > j) {
    swap(i, j);
  }

  parent[j] = i;
}

void UpdateAnsRange(int n, int m, int q) {
  Reset(n);

  for (int e = 1; e <= m; ++e) {
    query_nos[e].clear();
  }

  for (int k = 1; k <= q; ++k) {
    auto [l, r] = qans_range[k];
    if (l <= r) {
      query_nos[(l + r) / 2].push_back(k);
    }
  }

  for (int e = 1; e <= m; ++e) {
    Union(edges[e].first, edges[e].second);

    for (int k : query_nos[e]) {
      auto [l, r] = qans_range[k];
      if (l > r) {
        continue;
      }
      auto [i, j] = queries[k];
      qans_range[k] = Find(i) == Find(j) ? pii{l, e} : pii{e + 1, r};
    }
  }
}

int main() {
  int n, m, q;
  scanf("%d%d%d", &n, &m, &q);

  for (int e = 1; e <= m; ++e) {
    scanf("%d%d", &edges[e].first, &edges[e].second);
  }

  for (int k = 1; k <= q; ++k) {
    scanf("%d%d", &queries[k].first, &queries[k].second);
  }

  for (int k = 1; k <= q; ++k) {
    qans_range[k] = {0, m};
  }

  for (int b = 32 - __builtin_clz(m) + 5; b >= 0; --b) {
    UpdateAnsRange(n, m, q);
  }

  for (int k = 1; k <= q; ++k) {
    auto [l, r] = qans_range[k];
    printf("%d\n", l > r ? -1 : l);
  }

  return 0;
}