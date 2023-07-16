#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int, int>
#define pll pair<ll, ll>
#define N 4001

vector<vector<pii>> adj(N);
bool visited[N];
int color[N];

void Reset(int n, int m) {
  for (int i = 1; i <= n + m; ++i) {
    adj[i].clear();
    visited[i] = false;
    color[i] = false;
  }
}

void AddEdge(int i, int j, int c) {
  adj[i].push_back({j, c});
  adj[j].push_back({i, c});
}

bool DFS(int i, int ci) {
  if (visited[i]) {
    return color[i] == ci;
  }

  visited[i] = true;
  color[i] = ci;

  for (auto& p : adj[i]) {
    if (!DFS(p.first, ci ^ p.second)) {
      return false;
    }
  }

  return true;
}

bool Solve() {
  int n, m, k;
  scanf("%d%d%d", &n, &m, &k);

  Reset(n, m);

  while (k--) {
    int x1, y1, x2, y2;
    scanf("%d%d%d%d", &x1, &y1, &x2, &y2);

    if (y2 == y1 + 1) {
      AddEdge(x1, n + y1, 1);
    } else {
      AddEdge(x1, n + y1 - 1, 0);
    }
  }

  for (int i = 1; i <= n + m; ++i) {
    if (!DFS(i, color[i])) {
      return false;
    }
  }

  return true;
}

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    printf("%s\n", Solve() ? "YES" : "NO");
  }
  return 0;
}