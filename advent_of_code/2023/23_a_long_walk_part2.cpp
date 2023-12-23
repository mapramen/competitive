#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int, int>
#define pll pair<ll, ll>
#define tedge tuple<int, int, int>

vector<pii> directions = {{-1, 0}, {0, -1}, {0, 1}, {1, 0}};

vector<string> ReadGrid() {
  vector<string> s;
  while (true) {
    s.push_back("");
    if (!getline(cin, s.back())) {
      s.pop_back();
      break;
    }
  }
  return s;
}

int GetPosition(string& s) {
  for (int y = 0; y < s.size(); ++y) {
    if (s[y] == '.') {
      return y;
    }
  }
  return -1;
}

int GetIndex(int n, int m, int x, int y) {
  return m * x + y;
}

void PrintAdjStats(string name, vector<map<int, int>>& adj) {
  int n = adj.size();
  int cnt_v = 0, cnt_e = 0;
  for (int i = 0; i < n; ++i) {
    if (adj[i].empty()) {
      continue;
    }
    cnt_v += 1;
    cnt_e += adj[i].size();
  }
  cnt_e /= 2;
  printf("%s: cnt_v = %d, cnt_e = %d\n", name.c_str(), cnt_v, cnt_e);
}

void AddEdge(vector<map<int, int>>& adj, int i, int j, int w) {
  if (i == j) {
    return;
  }
  adj[i][j] = w;
  adj[j][i] = w;
}

void RemoveEdge(vector<map<int, int>>& adj, int i, int j) {
  adj[i].erase(j);
  adj[j].erase(i);
}

pii GetOtherEdge(vector<map<int, int>>& adj, int i, int j) {
  for (auto [k, w] : adj[i]) {
    if (k != j) {
      return {k, w};
    }
  }
  return {-1, -1};
}

void CondenseGraph(vector<map<int, int>>& adj) {
  queue<int> Q;

  int n = adj.size();
  for (int i = 0; i < n; ++i) {
    Q.push(i);
  }

  while (!Q.empty()) {
    int i = Q.front();
    Q.pop();

    if (adj[i].size() != 2) {
      continue;
    }

    auto [j, wj] = GetOtherEdge(adj, i, -1);
    auto [k, wk] = GetOtherEdge(adj, i, j);

    if (j == k) {
      continue;
    }

    RemoveEdge(adj, i, j);
    RemoveEdge(adj, i, k);

    int w = wj + wk;

    if (adj[j][k] >= w) {
      continue;
    }

    AddEdge(adj, j, k, w);

    Q.push(j);
    Q.push(k);
  }

  PrintAdjStats("After condensing", adj);
}

void PruneGraph(vector<map<int, int>>& adj, int s, int t) {
  int n = adj.size();

  queue<int> Q;
  for (int i = 0; i < n; ++i) {
    if (adj[i].size() == 1) {
      Q.push(i);
    }
  }

  while (!Q.empty()) {
    int i = Q.front();
    Q.pop();

    if (i == s || i == t) {
      continue;
    }

    auto [j, w] = *adj[i].begin();
    RemoveEdge(adj, i, j);

    if (adj[j].size() == 1) {
      Q.push(j);
    }
  }

  PrintAdjStats("After pruning", adj);
}

int DFS(vector<map<int, int>>& adj, vector<bool>& visited, int t, int i) {
  if (i == t) {
    return 0;
  }

  visited[i] = true;

  int ans = INT_MIN;
  for (auto [j, w] : adj[i]) {
    if (visited[j]) {
      continue;
    }
    ans = max(ans, w + DFS(adj, visited, t, j));
  }

  visited[i] = false;
  return ans;
}

int main() {
  vector<string> s = ReadGrid();

  int n = s.size(), m = s.front().size();
  vector<map<int, int>> adj(n * m);

  for (int x = 0; x < n; ++x) {
    for (int y = 1; y < m; ++y) {
      if (s[x][y - 1] == '#' || s[x][y] == '#') {
        continue;
      }

      int i = GetIndex(n, m, x, y - 1), j = GetIndex(n, m, x, y);
      AddEdge(adj, i, j, 1);
    }
  }

  for (int x = 1; x < n; ++x) {
    for (int y = 0; y < m; ++y) {
      if (s[x - 1][y] == '#' || s[x][y] == '#') {
        continue;
      }

      int i = GetIndex(n, m, x - 1, y), j = GetIndex(n, m, x, y);
      AddEdge(adj, i, j, 1);
    }
  }

  PrintAdjStats("Original", adj);

  int start_cell = GetIndex(n, m, 0, GetPosition(s.front()));
  int end_cell = GetIndex(n, m, n - 1, GetPosition(s.back()));

  PruneGraph(adj, start_cell, end_cell);
  CondenseGraph(adj);

  vector<bool> visited(n * m);

  int ans = DFS(adj, visited, end_cell, start_cell);

  cout << ans << endl;

  return 0;
}