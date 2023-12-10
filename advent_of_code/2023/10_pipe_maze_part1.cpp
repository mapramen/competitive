#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int, int>
#define pll pair<ll, ll>

int GetIndex(int n, int m, int x, int y) {
  if (x < 0 || x >= n || y < 0 || y >= m) {
    return -1;
  }
  return x * m + y;
}

void AddEdge(vector<vector<int>>& adj, int i, int j) {
  if (i < 0 || j < 0) {
    return;
  }

  adj[i].push_back(j);
  adj[j].push_back(i);
}

int DFS(vector<vector<int>>& adj, int start, int i, int p, int d) {
  if (i == start && p != -1) {
    return d;
  }

  for (int j : adj[i]) {
    if (j == p) {
      continue;
    }

    int ans = DFS(adj, start, j, i, d + 1);
    if (ans != -1) {
      return ans;
    }
  }

  return -1;
}

int main() {
  vector<string> s;

  while (true) {
    s.push_back("");
    if (!getline(cin, s.back())) {
      s.pop_back();
      break;
    }
  }

  int n = 2 * s.size();
  int m = 2 * s.front().size();

  vector<vector<int>> adj(n * m);
  int start = -1;

  for (int x = 1; x < n; x += 2) {
    for (int y = 1; y < m; y += 2) {
      char c = s[x / 2][y / 2];

      if (c == '.') {
        continue;
      }

      if (c == 'S') {
        start = GetIndex(n, m, x, y);
        AddEdge(adj, GetIndex(n, m, x, y), GetIndex(n, m, x - 1, y));
        AddEdge(adj, GetIndex(n, m, x, y), GetIndex(n, m, x, y - 1));
        AddEdge(adj, GetIndex(n, m, x, y), GetIndex(n, m, x, y + 1));
        AddEdge(adj, GetIndex(n, m, x, y), GetIndex(n, m, x + 1, y));
        continue;
      }

      if (c == '|') {
        AddEdge(adj, GetIndex(n, m, x - 1, y), GetIndex(n, m, x + 1, y));
        continue;
      }

      if (c == '-') {
        AddEdge(adj, GetIndex(n, m, x, y - 1), GetIndex(n, m, x, y + 1));
        continue;
      }

      if (c == 'L') {
        AddEdge(adj, GetIndex(n, m, x - 1, y), GetIndex(n, m, x, y + 1));
        continue;
      }

      if (c == 'J') {
        AddEdge(adj, GetIndex(n, m, x - 1, y), GetIndex(n, m, x, y - 1));
        continue;
      }

      if (c == '7') {
        AddEdge(adj, GetIndex(n, m, x, y - 1), GetIndex(n, m, x + 1, y));
        continue;
      }

      if (c == 'F') {
        AddEdge(adj, GetIndex(n, m, x, y + 1), GetIndex(n, m, x + 1, y));
        continue;
      }
    }
  }

  int ans = DFS(adj, start, start, -1, 0) / 2;

  cout << ans << endl;

  return 0;
}