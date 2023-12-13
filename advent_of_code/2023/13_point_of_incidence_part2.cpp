#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int, int>
#define pll pair<ll, ll>

vector<string> ReadPattern() {
  vector<string> ans;
  while (true) {
    string s;
    if (!getline(cin, s) || s.empty()) {
      break;
    }
    ans.push_back(s);
  }
  return ans;
}

ll Solve(vector<string> s) {
  int n = s.size(), m = s[0].size();

  for (int y = 1; y < m; ++y) {
    int cnt = 0;
    for (int y1 = y - 1, y2 = y; y1 >= 0 && y2 < m; --y1, ++y2) {
      for (int x = 0; x < n; ++x) {
        cnt += s[x][y1] != s[x][y2];
      }
    }

    if (cnt == 1) {
      return y;
    }
  }

  for (int x = 1; x < n; ++x) {
    int cnt = 0;
    for (int x1 = x - 1, x2 = x; x1 >= 0 && x2 < n; --x1, ++x2) {
      for (int y = 0; y < m; ++y) {
        cnt += s[x1][y] != s[x2][y];
      }
    }

    if (cnt == 1) {
      return 100 * x;
    }
  }

  return 0;
}

int main() {
  ll ans = 0;
  while (true) {
    vector<string> s = ReadPattern();
    if (s.empty()) {
      break;
    }
    ans += Solve(s);
  }
  cout << ans << endl;
  return 0;
}