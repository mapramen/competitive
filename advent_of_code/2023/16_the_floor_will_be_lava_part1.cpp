#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int, int>
#define pll pair<ll, ll>

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

void DFS(int n, int m, vector<string>& s, vector<vector<vector<bool>>>& visited, int x, int y, int direction) {
  if (x < 0 || x >= n || y < 0 || y >= m || visited[x][y][direction]) {
    return;
  }

  visited[x][y][direction] = true;

  char c = s[x][y];

  if (direction == 0) {
    if (c == '.') {
      DFS(n, m, s, visited, x, y + 1, 0);
    }

    if (c == '|') {
      DFS(n, m, s, visited, x - 1, y, 1);
      DFS(n, m, s, visited, x + 1, y, 3);
    }

    if (c == '/') {
      DFS(n, m, s, visited, x - 1, y, 1);
    }

    if (c == '\\') {
      DFS(n, m, s, visited, x + 1, y, 3);
    }

    if (c == '-') {
      DFS(n, m, s, visited, x, y + 1, 0);
    }
  }

  if (direction == 1) {
    if (c == '.') {
      DFS(n, m, s, visited, x - 1, y, 1);
    }

    if (c == '|') {
      DFS(n, m, s, visited, x - 1, y, 1);
    }

    if (c == '/') {
      DFS(n, m, s, visited, x, y + 1, 0);
    }

    if (c == '\\') {
      DFS(n, m, s, visited, x, y - 1, 2);
    }

    if (c == '-') {
      DFS(n, m, s, visited, x, y + 1, 0);
      DFS(n, m, s, visited, x, y - 1, 2);
    }
  }

  if (direction == 2) {
    if (c == '.') {
      DFS(n, m, s, visited, x, y - 1, 2);
    }

    if (c == '|') {
      DFS(n, m, s, visited, x - 1, y, 1);
      DFS(n, m, s, visited, x + 1, y, 3);
    }

    if (c == '/') {
      DFS(n, m, s, visited, x + 1, y, 3);
    }

    if (c == '\\') {
      DFS(n, m, s, visited, x - 1, y, 1);
    }

    if (c == '-') {
      DFS(n, m, s, visited, x, y - 1, 2);
    }
  }

  if (direction == 3) {
    if (c == '.') {
      DFS(n, m, s, visited, x + 1, y, 3);
    }

    if (c == '|') {
      DFS(n, m, s, visited, x + 1, y, 3);
    }

    if (c == '/') {
      DFS(n, m, s, visited, x, y - 1, 2);
    }

    if (c == '\\') {
      DFS(n, m, s, visited, x, y + 1, 0);
    }

    if (c == '-') {
      DFS(n, m, s, visited, x, y + 1, 0);
      DFS(n, m, s, visited, x, y - 1, 2);
    }
  }
}

int main() {
  vector<string> s = ReadGrid();

  int n = s.size(), m = s.front().size();
  vector<vector<vector<bool>>> visited(n, vector<vector<bool>>(m, vector<bool>(4, false)));

  DFS(n, m, s, visited, 0, 0, 0);

  int ans = 0;
  for (int x = 0; x < n; ++x) {
    for (int y = 0; y < m; ++y) {
      for (int direction = 0; direction < 4; ++direction) {
        if (visited[x][y][direction]) {
          ++ans;
          break;
        }
      }
    }
  }

  cout << ans << endl;

  return 0;
}