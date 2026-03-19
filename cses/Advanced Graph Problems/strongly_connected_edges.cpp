#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int, int>
#define pll pair<ll, ll>
#define N 200001

vector<vector<int>> adj(N);
int parent[N], start_time[N], timer = 0;
bool visited[N];
pii edges[N];

void Reset() {
  for (int i = 0; i < N; ++i) {
    adj[i].clear();
    parent[i] = 0;
    visited[i] = false;
  }

  timer = 0;
}

void DFS(int i, int p) {
  visited[i] = true;
  parent[i] = p;
  start_time[i] = ++timer;

  for (int j : adj[i]) {
    if (visited[j]) {
      continue;
    }
    DFS(j, i);
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

  DFS(1, 0);

  for (int e = 1; e <= m; ++e) {
    auto [i, j] = edges[e];
    if (start_time[i] > start_time[j]) {
      swap(i, j);
    }

    if (i != parent[j]) {
      swap(i, j);
    }

    edges[e] = {i, j};
  }

  Reset();
  for (int e = 1; e <= m; ++e) {
    auto [i, j] = edges[e];
    adj[i].push_back(j);
  }

  DFS(1, 0);

  for (int i = 1; i <= n; ++i) {
    if (!visited[i]) {
      printf("IMPOSSIBLE\n");
      return 0;
    }
  }

  Reset();
  for (int e = 1; e <= m; ++e) {
    auto [i, j] = edges[e];
    adj[j].push_back(i);
  }

  DFS(1, 0);

  for (int i = 1; i <= n; ++i) {
    if (!visited[i]) {
      printf("IMPOSSIBLE\n");
      return 0;
    }
  }

  for (int e = 1; e <= m; ++e) {
    auto [i, j] = edges[e];
    printf("%d %d\n", i, j);
  }

  return 0;
}