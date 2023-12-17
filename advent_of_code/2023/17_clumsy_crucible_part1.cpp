#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int, int>
#define pll pair<ll, ll>
#define tq tuple<int, int, int, int, int>
#define N 1000
#define K 4
#define MAX_STEPS_IN_A_DIRECTION 3

const vector<pii> directions{{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
int d[N][N][K][1 + MAX_STEPS_IN_A_DIRECTION];
priority_queue<tq, vector<tq>, greater<tq>> Q;

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

void CheckAndPush(int n, int m, vector<string>& s, int x, int y, int direction, int steps, int dxy) {
  auto [dx, dy] = directions[direction];

  x += dx, y += dy;
  if (x < 0 || x >= n || y < 0 || y >= m) {
    return;
  }

  dxy += s[x][y] - '0';
  if (d[x][y][direction][steps] <= dxy) {
    return;
  }

  d[x][y][direction][steps] = dxy;
  Q.push({dxy, x, y, direction, steps});
}

int main() {
  vector<string> s = ReadGrid();

  int n = s.size(), m = s.front().size();

  for (int x = 0; x < n; ++x) {
    for (int y = 0; y < m; ++y) {
      for (int k = 0; k < K; ++k) {
        for (int steps = 0; steps <= MAX_STEPS_IN_A_DIRECTION; ++steps) {
          d[x][y][k][steps] = INT_MAX;
        }
      }
    }
  }

  for (int k = 0; k < K; ++k) {
    CheckAndPush(n, m, s, 0, 0, k, 1, 0);
  }

  while (!Q.empty()) {
    auto [dxy, x, y, direction, steps] = Q.top();
    Q.pop();

    if (d[x][y][direction][steps] != dxy) {
      continue;
    }

    if (x == n - 1 && y == m - 1) {
      cout << dxy << endl;
      return 0;
    }

    if (steps < MAX_STEPS_IN_A_DIRECTION) {
      CheckAndPush(n, m, s, x, y, direction, steps + 1, dxy);
    }

    CheckAndPush(n, m, s, x, y, (direction + 1) % K, 1, dxy);
    CheckAndPush(n, m, s, x, y, (direction + K - 1) % K, 1, dxy);
  }

  return 0;
}