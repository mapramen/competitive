#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int, int>
#define pll pair<ll, ll>
#define N 200001

vector<vector<int>> adj(N);
pii edges[N];
int start_time[N], earliest_time[N], timer = 0;

void DFS(int i, int p) {
  start_time[i] = ++timer;
  earliest_time[i] = start_time[i];

  for (int j : adj[i]) {
    if (j == p) {
      continue;
    }

    if (start_time[j] == 0) {
      DFS(j, i);
      earliest_time[i] = min(earliest_time[i], earliest_time[j]);
    } else {
      earliest_time[i] = min(earliest_time[i], start_time[j]);
    }
  }
}

int main() {
  int n, m;
  scanf("%d%d", &n, &m);

  for (int e = 1; e <= m; ++e) {
    int i, j;
    scanf("%d%d", &i, &j);
    adj[i].push_back(j);
    adj[j].push_back(i);
    edges[e] = {i, j};
  }

  for (int i = 1; i <= n; ++i) {
    if (start_time[i] == 0) {
      DFS(i, 0);
    }
  }

  vector<pii> bridges;
  for (int e = 1; e <= m; ++e) {
    int i = edges[e].first;
    int j = edges[e].second;

    if (start_time[i] > start_time[j]) {
      swap(i, j);
    }

    if (earliest_time[j] > start_time[i]) {
      bridges.push_back({i, j});
    }
  }

  printf("%lu\n", bridges.size());
  for (auto [i, j] : bridges) {
    printf("%d %d\n", i, j);
  }

  return 0;
}