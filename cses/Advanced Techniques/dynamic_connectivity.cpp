#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int, int>
#define pll pair<ll, ll>
#define trollback tuple<int, int, int>
#define N 100001
#define M (1 << 18)

int qans[N], parent[N], sz[N];
map<pii, int> edges_start_time_map;
vector<pii> T[M];

void Reset(int n) {
  for (int i = 1; i <= n; ++i) {
    parent[i] = i, sz[i] = 1;
  }
}

int Find(int i) {
  return parent[i] == i ? i : Find(parent[i]);
}

void AddRollback(vector<trollback>& rollbacks, int i) {
  rollbacks.push_back({i, parent[i], sz[i]});
}

int Union(vector<trollback>& rollbacks, int i, int j) {
  i = Find(i), j = Find(j);
  if (i == j) {
    return 0;
  }

  if (sz[i] < sz[j]) {
    swap(i, j);
  }

  AddRollback(rollbacks, j);
  AddRollback(rollbacks, i);

  parent[j] = i;
  sz[i] += sz[j];
  return 1;
}

void AddEdge(int k, int l, int r, int ql, int qr, int i, int j) {
  if (l > qr || r < ql) {
    return;
  }

  if (ql <= l && r <= qr) {
    T[k].push_back({i, j});
    return;
  }

  int m = (l + r) / 2;
  AddEdge(2 * k + 1, l, m, ql, qr, i, j);
  AddEdge(2 * k + 2, m + 1, r, ql, qr, i, j);
}

void DivideAndConquer(int k, int l, int r, int ans) {
  vector<trollback> rollbacks;
  for (auto [i, j] : T[k]) {
    ans -= Union(rollbacks, i, j);
  }

  if (l == r) {
    qans[l] = ans;
  } else {
    int m = (l + r) / 2;
    DivideAndConquer(2 * k + 1, l, m, ans);
    DivideAndConquer(2 * k + 2, m + 1, r, ans);
  }

  for (auto [i, p, s] : rollbacks) {
    parent[i] = p;
    sz[i] = s;
  }
  rollbacks.clear();
}

int main() {
  int n, m, q;
  scanf("%d%d%d", &n, &m, &q);

  while (m--) {
    int i, j;
    scanf("%d%d", &i, &j);
    if (i > j) {
      swap(i, j);
    }
    edges_start_time_map[{i, j}] = 0;
  }

  for (int k = 1; k <= q; ++k) {
    int t, i, j;
    scanf("%d%d%d", &t, &i, &j);

    if (i > j) {
      swap(i, j);
    }

    if (t == 1) {
      edges_start_time_map[{i, j}] = k;
    } else {
      AddEdge(0, 0, q, edges_start_time_map[{i, j}], k - 1, i, j);
      edges_start_time_map.erase({i, j});
    }
  }

  for (auto [edge, start_time] : edges_start_time_map) {
    AddEdge(0, 0, q, start_time, q, edge.first, edge.second);
  }

  Reset(n);

  DivideAndConquer(0, 0, q, n);

  for (int k = 0; k <= q; ++k) {
    printf("%d ", qans[k]);
  }
  printf("\n");

  return 0;
}