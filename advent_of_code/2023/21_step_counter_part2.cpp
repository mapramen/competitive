#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int, int>
#define pll pair<ll, ll>
#define NUMBER_OF_STEPS 26501365

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
      if (s[x][y] == 'S') {
        s[x][y] = '.';
        return {x, y};
      }
    }
  }
  return {-1, -1};
}

ll GetValue(vector<ll>& y, int x) {
  ll c = y[0];
  ll b = (-3 * y[0] + 4 * y[1] - y[2]) / 2;
  ll a = (y[2] - 2 * y[1] + y[0]) / 2;
  return a * x * x + b * x + c;
}

int main() {
  vector<string> s = ReadGrid();

  int n = s.size(), m = s.front().size();
  set<pii> S = {GetStartPosition(s)};

  vector<ll> y;
  for (int steps = 1; y.size() < 3; ++steps) {
    set<pii> T;
    for (auto [x, y] : S) {
      for (auto [dx, dy] : directions) {
        int nx = x + dx, ny = y + dy;
        int mx = nx % n, my = ny % m;
        mx = (n + mx) % n, my = (m + my) % m;
        if (s[mx][my] == '#') {
          continue;
        }
        T.insert({nx, ny});
      }
    }
    S = T;
    if (steps % n == NUMBER_OF_STEPS % n) {
      y.push_back(S.size());
    }
  }

  cout << GetValue(y, NUMBER_OF_STEPS / n) << '\n';

  return 0;
}