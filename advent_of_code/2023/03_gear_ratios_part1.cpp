#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int, int>
#define pll pair<ll, ll>

bool IsValid(vector<string>& s, int x, int y) {
  for (int dx = -1; dx < 2; ++dx) {
    for (int dy = -1; dy < 2; ++dy) {
      int nx = x + dx, ny = y + dy;
      if (nx < 0 || nx >= s.size() || ny < 0 || ny >= s[nx].size()) {
        continue;
      }

      if (s[nx][ny] != '.' && !isdigit(s[nx][ny])) {
        return true;
      }
    }
  }
  return false;
}

bool IsValid(vector<string>& s, int x, vector<int>& v) {
  for (int y : v) {
    if (IsValid(s, x, y)) {
      return true;
    }
  }
  return false;
}

int main() {
  vector<string> s;

  for (string line; getline(cin, line);) {
    s.push_back(line);
  }

  int ans = 0;
  for (int n = s.size(), x = 0; x < n; ++x) {
    for (int m = s[x].size(), y = 0; y < m; ++y) {
      if (!isdigit(s[x][y])) {
        continue;
      }

      vector<int> v;
      for (; y < m && isdigit(s[x][y]); ++y) {
        v.push_back(y);
      }

      if (IsValid(s, x, v)) {
        ans += stoi(s[x].substr(v.front(), v.size()));
      }

      y = v.back();
    }
  }

  cout << ans << endl;

  return 0;
}