#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int, int>
#define pll pair<ll, ll>

ll CalculateDistance(vector<int>& a) {
  ll ans = 0;
  for (ll n = a.size(), x = 0, cnt = 0, dis = 0; x < n; dis += cnt, ++x) {
    if (a[x] == 0) {
      dis += 999999 * cnt;
    }
    ans += a[x] * dis;
    cnt += a[x];
  }
  return ans;
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

  int n = s.size(), m = s.front().size();
  vector<int> rows(n), columns(m);

  for (int x = 0; x < n; ++x) {
    for (int y = 0; y < m; ++y) {
      if (s[x][y] == '#') {
        ++rows[x];
        ++columns[y];
      }
    }
  }

  ll ans = CalculateDistance(rows) + CalculateDistance(columns);

  cout << ans << endl;

  return 0;
}