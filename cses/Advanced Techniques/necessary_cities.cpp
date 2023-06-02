#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int, int>
#define pll pair<ll, ll>
#define N 200001

vector<vector<int>> adj(N);
pii edges[N];
int parent[N], start_time[N], earliest_time[N], timer = 0;

void DFS(int i, int p) {
  parent[i] = p;
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

  vector<int> articulation_points;
  for (int i = 1; i <= n; ++i) {
    int branch_cnt = 0;
    for (int j : adj[i]) {
      branch_cnt += (parent[j] == i || j == parent[i]);
    }

    bool is_articulation_point = false;

    for (int j : adj[i]) {
      if (i != parent[j]) {
        continue;
      }

      if (branch_cnt > 1 && earliest_time[j] >= start_time[i]) {
        is_articulation_point = true;
        break;
      }
    }

    if (is_articulation_point) {
      articulation_points.push_back(i);
    }
  }

  printf("%lu\n", articulation_points.size());
  for (int i : articulation_points) {
    printf("%d ", i);
  }
  printf("\n");

  return 0;
}