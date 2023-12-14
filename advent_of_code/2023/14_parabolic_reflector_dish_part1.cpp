#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int, int>
#define pll pair<ll, ll>

int main() {
  vector<string> s;

  while (true) {
    s.push_back("");
    if (!getline(cin, s.back())) {
      s.pop_back();
      break;
    }
  }

  int n = s.size(), m = s.front().size();
  for (int x = 1; x < n; ++x) {
    for (int y = 0; y < m; ++y) {
      if (s[x][y] != 'O') {
        continue;
      }

      int nx = x - 1;
      while (nx > -1 && s[nx][y] == '.') {
        --nx;
      }
      ++nx;

      swap(s[x][y], s[nx][y]);
    }
  }

  int ans = 0;
  for (int x = 0; x < n; ++x) {
    for (int y = 0; y < m; ++y) {
      if (s[x][y] == 'O') {
        ans += (n - x);
      }
    }
  }

  cout << ans << endl;

  return 0;
}