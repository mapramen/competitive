#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int, int>
#define pll pair<ll, ll>

vector<string> SpinCycle(vector<string> s) {
  int n = s.size(), m = s.front().size();

  // tilt north
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

  // tilt west
  for (int y = 1; y < m; ++y) {
    for (int x = 0; x < n; ++x) {
      if (s[x][y] != 'O') {
        continue;
      }

      int ny = y - 1;
      while (ny > -1 && s[x][ny] == '.') {
        --ny;
      }
      ++ny;

      swap(s[x][y], s[x][ny]);
    }
  }

  // tilt south
  for (int x = n - 2; x > -1; --x) {
    for (int y = 0; y < m; ++y) {
      if (s[x][y] != 'O') {
        continue;
      }

      int nx = x + 1;
      while (nx < n && s[nx][y] == '.') {
        ++nx;
      }
      --nx;

      swap(s[x][y], s[nx][y]);
    }
  }

  // tilt east
  for (int y = m - 2; y > -1; --y) {
    for (int x = 0; x < n; ++x) {
      if (s[x][y] != 'O') {
        continue;
      }

      int ny = y + 1;
      while (ny < m && s[x][ny] == '.') {
        ++ny;
      }
      --ny;

      swap(s[x][y], s[x][ny]);
    }
  }

  return s;
}

int GetNorthLoad(vector<string>& s) {
  int n = s.size(), m = s.front().size();

  int ans = 0;
  for (int x = 0; x < n; ++x) {
    for (int y = 0; y < m; ++y) {
      if (s[x][y] == 'O') {
        ans += (n - x);
      }
    }
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

  vector<vector<string>> states{s};
  map<vector<string>, int> state_index_map;
  state_index_map[s] = 0;

  for (int i = 1;; ++i) {
    s = SpinCycle(s);

    auto it = state_index_map.find(s);

    if (it == state_index_map.end()) {
      state_index_map[s] = i;
      states.push_back(s);
      continue;
    }

    int j = it->second;
    int len = i - j;
    int k = (1000000000 - j) % len;
    s = states[j + k];
    break;
  }

  cout << GetNorthLoad(s) << endl;

  return 0;
}