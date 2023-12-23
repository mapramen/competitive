#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int, int>
#define pll pair<ll, ll>

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

pii GetStartPosition(vector<string>& s) {
  for (int x = 0; x < s.size(); ++x) {
    for (int y = 0; y < s[x].size(); ++y) {
      if (s[x][y] == '.') {
        return {x, y};
      }
    }
  }
  return {-1, -1};
}

int DFS(int n, int m, vector<string>& s, set<pii>& S, int x, int y) {
  if (x < 0 || x >= n || y < 0 || y >= m || s[x][y] == '#' || S.count({x, y}) != 0) {
    return INT_MIN;
  }

  S.insert({x, y});

  int ans = x == n - 1 && s[x][y] == '.' ? 0 : INT_MIN;
  if (s[x][y] == '^') {
    ans = 1 + DFS(n, m, s, S, x - 1, y);
  }

  if (s[x][y] == 'v') {
    ans = 1 + DFS(n, m, s, S, x + 1, y);
  }

  if (s[x][y] == '<') {
    ans = 1 + DFS(n, m, s, S, x, y - 1);
  }

  if (s[x][y] == '>') {
    ans = 1 + DFS(n, m, s, S, x, y + 1);
  }

  if (s[x][y] == '.') {
    for (auto [dx, dy] : directions) {
      ans = max(ans, 1 + DFS(n, m, s, S, x + dx, y + dy));
    }
  }

  S.erase({x, y});
  return ans;
}

int main() {
  vector<string> s = ReadGrid();

  auto [sx, sy] = GetStartPosition(s);

  int n = s.size(), m = s.front().size();

  set<pii> S;
  int ans = DFS(n, m, s, S, sx, sy);

  cout << ans << endl;

  return 0;
}