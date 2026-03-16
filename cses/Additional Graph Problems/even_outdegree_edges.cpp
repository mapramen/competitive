#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int, int>
#define pll pair<ll, ll>
#define N 200001

vector<vector<int>> adj(N);
int start_time[N], finish_time[N], timer = 0;
vector<pii> directed_edges;

int DFS(int i, int p) {
  if (start_time[i] != 0) {
    return 0;
  }

  start_time[i] = ++timer;
  int outdegree_parity = 0;
  for (int j : adj[i]) {
    if (j == p || start_time[j] != 0 && finish_time[j] == 0) {
      continue;
    }

    if (DFS(j, i) == 0) {
      outdegree_parity ^= 1;
      directed_edges.push_back({i, j});
      continue;
    }

    directed_edges.push_back({j, i});
  }

  finish_time[i] = timer;
  return outdegree_parity;
}

int main() {
  int n, m;
  scanf("%d%d", &n, &m);

  while (m--) {
    int i, j;
    scanf("%d%d", &i, &j);
    adj[i].push_back(j);
    adj[j].push_back(i);
  }

  for (int i = 1; i <= n; ++i) {
    if (DFS(i, 0) == 1) {
      printf("IMPOSSIBLE\n");
      return 0;
    }
  }

  for (auto [i, j] : directed_edges) {
    printf("%d %d\n", i, j);
  }

  return 0;
}