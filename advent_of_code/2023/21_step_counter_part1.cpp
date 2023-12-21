#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int, int>
#define pll pair<ll, ll>
#define NUMBER_OF_STEPS 64

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

int main() {
  vector<string> s = ReadGrid();

  int n = s.size(), m = s.front().size();
  set<pii> S = {GetStartPosition(s)};

  for (int steps = 1; steps <= NUMBER_OF_STEPS; ++steps) {
    set<pii> T;
    for (auto [x, y] : S) {
      for (auto [dx, dy] : directions) {
        int nx = x + dx, ny = y + dy;
        if (nx < 0 || nx >= n || ny < 0 || ny >= m || s[nx][ny] == '#') {
          continue;
        }
        T.insert({nx, ny});
      }
    }
    S = T;
  }

  cout << S.size() << '\n';

  return 0;
}