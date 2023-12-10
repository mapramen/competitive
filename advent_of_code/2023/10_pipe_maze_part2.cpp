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

void AddEdge(vector<vector<pii>>& adj, int i, int j, int mid) {
  if (i < 0 || j < 0) {
    return;
  }

  adj[i].push_back({j, mid});
  adj[j].push_back({i, mid});
}

int DFS(vector<vector<pii>>& adj, vector<bool>& visited, int start, int i, int p, int d) {
  if (i == start && p != -1) {
    return d;
  }

  for (auto [j, mid] : adj[i]) {
    if (j == p) {
      continue;
    }

    int ans = DFS(adj, visited, start, j, i, d + 1);
    if (ans != -1) {
      visited[i] = true;
      visited[mid] = true;
      return ans;
    }
  }

  return -1;
}

void Print(vector<bool>& visited, int n, int m) {
  for (int x = 1; x < n; x += 2) {
    for (int y = 1; y < m; y += 2) {
      if (visited[GetIndex(n, m, x, y)]) {
        cout << "X";
      } else {
        cout << ".";
      }
    }
    cout << endl;
  }
}

void MarkNonEnclosedDFS(vector<bool>& visited, int n, int m, int x, int y) {
  int i = GetIndex(n, m, x, y);
  if (i == -1 || visited[i]) {
    return;
  }

  visited[i] = true;

  MarkNonEnclosedDFS(visited, n, m, x - 1, y);
  MarkNonEnclosedDFS(visited, n, m, x, y - 1);
  MarkNonEnclosedDFS(visited, n, m, x, y + 1);
  MarkNonEnclosedDFS(visited, n, m, x + 1, y);
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

  vector<vector<pii>> adj(n * m);
  int start = -1;

  for (int x = 1; x < n; x += 2) {
    for (int y = 1; y < m; y += 2) {
      char c = s[x / 2][y / 2];

      if (c == '.') {
        continue;
      }

      if (c == 'S') {
        start = GetIndex(n, m, x, y);
        AddEdge(adj, GetIndex(n, m, x, y), GetIndex(n, m, x - 1, y), GetIndex(n, m, x, y));
        AddEdge(adj, GetIndex(n, m, x, y), GetIndex(n, m, x, y - 1), GetIndex(n, m, x, y));
        AddEdge(adj, GetIndex(n, m, x, y), GetIndex(n, m, x, y + 1), GetIndex(n, m, x, y));
        AddEdge(adj, GetIndex(n, m, x, y), GetIndex(n, m, x + 1, y), GetIndex(n, m, x, y));
        continue;
      }

      if (c == '|') {
        AddEdge(adj, GetIndex(n, m, x - 1, y), GetIndex(n, m, x + 1, y), GetIndex(n, m, x, y));
        continue;
      }

      if (c == '-') {
        AddEdge(adj, GetIndex(n, m, x, y - 1), GetIndex(n, m, x, y + 1), GetIndex(n, m, x, y));
        continue;
      }

      if (c == 'L') {
        AddEdge(adj, GetIndex(n, m, x - 1, y), GetIndex(n, m, x, y + 1), GetIndex(n, m, x, y));
        continue;
      }

      if (c == 'J') {
        AddEdge(adj, GetIndex(n, m, x - 1, y), GetIndex(n, m, x, y - 1), GetIndex(n, m, x, y));
        continue;
      }

      if (c == '7') {
        AddEdge(adj, GetIndex(n, m, x, y - 1), GetIndex(n, m, x + 1, y), GetIndex(n, m, x, y));
        continue;
      }

      if (c == 'F') {
        AddEdge(adj, GetIndex(n, m, x, y + 1), GetIndex(n, m, x + 1, y), GetIndex(n, m, x, y));
        continue;
      }
    }
  }

  vector<bool> visited(n * m);
  DFS(adj, visited, start, start, -1, 0);

  // Print(visited, n, m);

  for (int x = 0; x < n; ++x) {
    for (int y = 0; y < m; ++y) {
      if (x == 0 || x == n - 1 || y == 0 || y == m - 1) {
        MarkNonEnclosedDFS(visited, n, m, x, y);
      }
    }
  }

  // Print(visited, n, m);

  int ans = 0;
  for (int x = 1; x < n; x += 2) {
    for (int y = 1; y < m; y += 2) {
      ans += !visited[GetIndex(n, m, x, y)];
    }
  }

  cout << ans << endl;

  return 0;
}