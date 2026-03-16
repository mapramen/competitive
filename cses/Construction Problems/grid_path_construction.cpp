#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int, int>
#define pll pair<ll, ll>
#define tq tuple<int, int, int, int, int, int>
#define tedge tuple<int, int, int, int>

map<tq, vector<tedge>> dp;
vector<tedge> path;
set<pii> S;
const vector<pii> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

int Size(int n, int m) {
  return n * m;
}

int Size(int n1, int m1, int n2, int m2) {
  return Size(n2 - n1 + 1, m2 - m1 + 1);
}

bool IsEvenSized(int n1, int m1, int n2, int m2) {
  return Size(n1, m1, n2, m2) % 2 == 0;
}

bool IsSamePoint(int y1, int x1, int y2, int x2) {
  return y1 == y2 && x1 == x2;
}

int Color(int x, int y) {
  return (x + y) % 2;
}

bool Check3(int sy, int sx, int ty, int tx) {
  return (sy == 2 && sx < tx) || (sx < tx - 1);
}

int U(int n, int m, int sy, int sx, int ty, int tx) {
  if (n > m) {
    return U(m, n, sx, sy, tx, ty);
  }

  if (n == 1) {
    return abs(tx - sx) + 1;
  }

  if (n == 2 && sy != ty && abs(sx - tx) <= 1) {
    return max(sx + tx, 2 * m - sx - tx + 2);
  }

  if (n == 3 && m % 2 == 0 && Color(sx, sy) != Color(tx, ty)) {
    if (Color(sx, sy) == 0) {
      return U(n, m, sy, m - sx + 1, ty, m - tx + 1);
    }

    if (Check3(sy, sx, ty, tx)) {
      return n * m - 2;
    }
  }

  if ((n * m) % 2 == 0) {
    return n * m - (Color(sx, sy) == Color(tx, ty));
  }

  if (Color(sx, sy) == 0 && Color(tx, ty) == 0) {
    return n * m;
  }

  if (Color(sx, sy) == 1 && Color(tx, ty) == 1) {
    return n * m - 2;
  }

  return n * m - 1;
}

bool IsHamiltonPath(int n, int m, int sy, int sx, int ty, int tx) {
  return !IsSamePoint(sy, sx, ty, tx) && (U(n, m, sy, sx, ty, tx) == Size(n, m));
}

bool IsHamiltonPath(int n1, int m1, int n2, int m2, int sy, int sx, int ty, int tx) {
  return IsHamiltonPath(n2 - n1 + 1, m2 - m1 + 1, sy - n1 + 1, sx - m1 + 1, ty - n1 + 1, tx - m1 + 1);
}

bool IsEdgePresent(vector<vector<set<pii>>>& adj, bool transpose, int y1, int x1, int y2, int x2) {
  if (transpose) {
    swap(y1, x1);
    swap(y2, x2);
  }

  return adj[y1][x1].count({y2, x2}) > 0;
}

void AddEdge(vector<vector<set<pii>>>& adj, bool transpose, int y1, int x1, int y2, int x2) {
  if (transpose) {
    swap(y1, x1);
    swap(y2, x2);
  }

  adj[y1][x1].insert({y2, x2});
  adj[y2][x2].insert({y1, x1});
}

void RemoveEdge(vector<vector<set<pii>>>& adj, bool transpose, int y1, int x1, int y2, int x2) {
  if (transpose) {
    swap(y1, x1);
    swap(y2, x2);
  }

  adj[y1][x1].erase({y2, x2});
  adj[y2][x2].erase({y1, x1});
}

void HamiltonCycle(vector<vector<set<pii>>>& adj, bool transpose, int n1, int m1, int n2, int m2) {
  if (n2 == n1 + 1) {
    for (int m = m1 + 1; m <= m2; ++m) {
      AddEdge(adj, transpose, n1, m - 1, n1, m);
      AddEdge(adj, transpose, n2, m - 1, n2, m);
    }

    AddEdge(adj, transpose, n1, m1, n2, m1);
    AddEdge(adj, transpose, n1, m2, n2, m2);
    return;
  }

  if (m2 == m1 + 1) {
    return HamiltonCycle(adj, !transpose, m1, n1, m2, n2);
  }

  if ((n2 - n1 + 1) % 2 != 0) {
    return HamiltonCycle(adj, !transpose, m1, n1, m2, n2);
  }

  for (int n = n1; n <= n2; ++n) {
    for (int m = m1 + 2; m <= m2; ++m) {
      AddEdge(adj, transpose, n, m - 1, n, m);
    }
  }

  for (int n = n1 + 1; n <= n2; ++n) {
    AddEdge(adj, transpose, n - 1, m1, n, m1);
  }

  for (int n = n1 + 2; n <= n2; n += 2) {
    AddEdge(adj, transpose, n - 1, m1 + 1, n, m1 + 1);
  }

  for (int n = n1 + 1; n <= n2; n += 2) {
    AddEdge(adj, transpose, n, m2, n - 1, m2);
  }

  AddEdge(adj, transpose, n1, m1, n1, m1 + 1);
  AddEdge(adj, transpose, n2, m1, n2, m1 + 1);
}

void MergeStrip(vector<vector<set<pii>>>& adj, bool transpose, int n1, int n2, int m) {
  for (int y = n1 + 1; y <= n2; ++y) {
    if (!IsEdgePresent(adj, transpose, y - 1, m, y, m) || !IsEdgePresent(adj, transpose, y - 1, m + 1, y, m + 1)) {
      continue;
    }

    RemoveEdge(adj, transpose, y - 1, m, y, m);
    RemoveEdge(adj, transpose, y - 1, m + 1, y, m + 1);

    AddEdge(adj, transpose, y - 1, m, y - 1, m + 1);
    AddEdge(adj, transpose, y, m, y, m + 1);
    break;
  }
}

void DFS(int n, int m, int y1, int x1, int y2, int x2) {
  S.insert({y2, x2});

  tq key = {n, m, y1, x1, y2, x2};
  if (path.size() > dp[key].size()) {
    dp[key] = path;
  }

  for (auto [dy, dx] : directions) {
    int ny = y2 + dy, nx = x2 + dx;
    if (ny <= 0 || ny > n || nx <= 0 || nx > m || S.count({ny, nx}) > 0) {
      continue;
    }
    path.push_back({y2, x2, ny, nx});
    DFS(n, m, y1, x1, ny, nx);
    path.pop_back();
  }

  S.erase({y2, x2});
}

vector<tedge> Solve(int n, int m, int y1, int x1, int y2, int x2) {
  if (n > m) {
    return Solve(m, n, x1, y1, x2, y2);
  }

  if (y1 > y2) {
    return Solve(n, m, y2, x2, y1, x1);
  }

  tq key = {n, m, y1, x1, y2, x2};
  auto it = dp.find(key);
  if (it != dp.end()) {
    return it->second;
  }

  DFS(n, m, y1, x1, y1, x1);
  return dp[key];
}

void Solve(vector<vector<set<pii>>>& adj, bool transpose, int n1, int m1, int n2, int m2, int y1, int x1, int y2, int x2) {
  if (n1 == n2) {
    for (int x = m1 + 1; x <= m2; ++x) {
      AddEdge(adj, transpose, n1, x - 1, n1, x);
    }
    return;
  }

  if (m1 == m2) {
    Solve(adj, !transpose, m1, n1, m2, n2, x1, y1, x2, y2);
    return;
  }

  if (x1 > x2) {
    swap(x1, x2);
    swap(y1, y2);
  }

  for (int m = x1; m < x2; ++m) {
    for (int n = n1; n <= n2; ++n) {
      if (!(IsHamiltonPath(n1, m1, n2, m, y1, x1, n, m) && IsHamiltonPath(n1, m + 1, n2, m2, n, m + 1, y2, x2))) {
        continue;
      }

      Solve(adj, transpose, n1, m1, n2, m, y1, x1, n, m);
      Solve(adj, transpose, n1, m + 1, n2, m2, n, m + 1, y2, x2);
      AddEdge(adj, transpose, n, m, n, m + 1);
      return;
    }
  }

  if (y1 > y2) {
    swap(x1, x2);
    swap(y1, y2);
  }

  for (int n = y1; n < y2; ++n) {
    for (int m = m1; m <= m2; ++m) {
      if (!(IsHamiltonPath(n1, m1, n, m2, y1, x1, n, m) && IsHamiltonPath(n + 1, m1, n2, m2, n + 1, m, y2, x2))) {
        continue;
      }

      Solve(adj, transpose, n1, m1, n, m2, y1, x1, n, m);
      Solve(adj, transpose, n + 1, m1, n2, m2, n + 1, m, y2, x2);
      AddEdge(adj, transpose, n, m, n + 1, m);
      return;
    }
  }

  if (x1 > x2) {
    swap(x1, x2);
    swap(y1, y2);
  }

  for (int m = m1 + 1; m < x1; ++m) {
    if (!(IsEvenSized(n1, m1, n2, m) && IsHamiltonPath(n1, m + 1, n2, m2, y1, x1, y2, x2))) {
      continue;
    }

    HamiltonCycle(adj, transpose, n1, m1, n2, m);
    Solve(adj, transpose, n1, m + 1, n2, m2, y1, x1, y2, x2);
    MergeStrip(adj, transpose, n1, n2, m);
    return;
  }

  for (int m = x2 + 1; m < m2; ++m) {
    if (!(IsEvenSized(n1, m, n2, m2) && IsHamiltonPath(n1, m1, n2, m - 1, y1, x1, y2, x2))) {
      continue;
    }

    HamiltonCycle(adj, transpose, n1, m, n2, m2);
    Solve(adj, transpose, n1, m1, n2, m - 1, y1, x1, y2, x2);
    MergeStrip(adj, transpose, n1, n2, m - 1);
    return;
  }

  if (y1 > y2) {
    swap(x1, x2);
    swap(y1, y2);
  }

  for (int n = n1 + 1; n < y1; ++n) {
    if (!(IsEvenSized(n1, m1, n, m2) && IsHamiltonPath(n + 1, m1, n2, m2, y1, x1, y2, x2))) {
      continue;
    }

    HamiltonCycle(adj, transpose, n1, m1, n, m2);
    Solve(adj, transpose, n + 1, m1, n2, m2, y1, x1, y2, x2);
    MergeStrip(adj, !transpose, m1, m2, n);
    return;
  }

  for (int n = y2 + 1; n < n2; ++n) {
    if (!(IsEvenSized(n, m1, n2, m2) && IsHamiltonPath(n1, m1, n - 1, m2, y1, x1, y2, x2))) {
      continue;
    }

    HamiltonCycle(adj, transpose, n, m1, n2, m2);
    Solve(adj, transpose, n1, m1, n - 1, m2, y1, x1, y2, x2);
    MergeStrip(adj, !transpose, m1, m2, n - 1);
    return;
  }

  for (auto [yi, xi, yj, xj] : Solve(n2 - n1 + 1, m2 - m1 + 1, y1 - n1 + 1, x1 - m1 + 1, y2 - n1 + 1, x2 - m1 + 1)) {
    AddEdge(adj, transpose, yi + n1 - 1, xi + m1 - 1, yj + n1 - 1, xj + m1 - 1);
  }
}

void GenerateAnsString(string& s, vector<vector<set<pii>>>& adj, int y, int x) {
  if (adj[y][x].empty()) {
    return;
  }

  auto [yi, xi] = *adj[y][x].begin();
  RemoveEdge(adj, false, y, x, yi, xi);

  if (yi == y - 1) {
    s.push_back('U');
  } else if (yi == y + 1) {
    s.push_back('D');
  } else if (xi == x - 1) {
    s.push_back('L');
  } else {
    s.push_back('R');
  }

  GenerateAnsString(s, adj, yi, xi);
}

string Solve() {
  int n, m, y1, x1, y2, x2;
  scanf("%d%d%d%d%d%d", &n, &m, &y1, &x1, &y2, &x2);

  if (!IsHamiltonPath(n, m, y1, x1, y2, x2)) {
    return "";
  }

  vector<vector<set<pii>>> adj(n + 1, vector<set<pii>>(m + 1));
  Solve(adj, false, 1, 1, n, m, y1, x1, y2, x2);

  string ans;
  GenerateAnsString(ans, adj, y1, x1);
  return ans;
}

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    string ans = Solve();
    if (ans.empty()) {
      printf("NO\n");
    } else {
      printf("YES\n");
      printf("%s\n", ans.c_str());
    }
  }
  return 0;
}