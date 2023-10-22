#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int, int>
#define pll pair<ll, ll>

string DespiralizeString(int n, int m, string s) {
  vector<string> a(n, string(m, ' '));

  for (int x = 0, z = 0; x < n; ++x) {
    for (int y = 0; y < m; ++y) {
      a[x][y] = s[z++];
    }
  }

  for (int x1 = 0, x2 = n - 1, y1 = 0, y2 = m - 1, z = 0; x1 <= x2 && y1 <= y2; ++x1, --x2, ++y1, --y2) {
    for (int y = y1; y <= y2; ++y) {
      s[z++] = a[x1][y];
    }

    for (int x = x1 + 1; x <= x2; ++x) {
      s[z++] = a[x][y2];
    }

    if (x2 != x1) {
      for (int y = y2 - 1; y >= y1; --y) {
        s[z++] = a[x2][y];
      }
    }

    if (y1 != y2) {
      for (int x = x2 - 1; x > x1; --x) {
        s[z++] = a[x][y1];
      }
    }
  }

  return s;
}

string DecodeString(string s) {
  string ans;
  for (int n = s.size(), i = 0; i < n; i += 5) {
    int x = stoi(string(s, i, min(5, n - i)), nullptr, 2);
    ans.push_back(x == 0 ? ' ' : 'A' + x - 1);
  }

  while (ans.size() > 1 && ans.back() == ' ') {
    ans.pop_back();
  }

  return ans;
}

string Solve() {
  int n, m;
  string s;
  cin >> n >> m >> s;
  return DecodeString(DespiralizeString(n, m, s));
}

int main() {
  int t;
  scanf("%d", &t);
  for (int k = 1; k <= t; ++k) {
    printf("%d %s\n", k, Solve().c_str());
  }
  return 0;
}