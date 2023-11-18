#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int, int>
#define pll pair<ll, ll>
#define N 101

char s[N][N];
int d[N][N];
queue<pii> Q;

pii GetCoordinates(int n, int m, char c) {
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      d[i][j] = -1;
      if (s[i][j] == c) {
        return {i, j};
      }
    }
  }

  return {-1, -1};
}

void CheckAndPush(int n, int m, int x, int y, int dxy) {
  if (x < 0 || x >= n || y < 0 || y >= m || s[x][y] == '*') {
    return;
  }

  s[x][y] = '*';
  d[x][y] = dxy;
  Q.push({x, y});
}

int Solve() {
  int n, m;
  scanf("%d%d", &n, &m);

  for (int i = 0; i < n; ++i) {
    scanf("%s", s[i]);
  }

  auto [sx, sy] = GetCoordinates(n, m, '$');
  auto [tx, ty] = GetCoordinates(n, m, '#');

  while (!Q.empty()) {
    Q.pop();
  }

  CheckAndPush(n, m, sx, sy, 0);
  while (!Q.empty()) {
    auto [x, y] = Q.front();
    Q.pop();

    if (x == tx && y == ty) {
      return d[x][y];
    }

    CheckAndPush(n, m, x - 1, y, d[x][y] + 1);
    CheckAndPush(n, m, x + 1, y, d[x][y] + 1);
    CheckAndPush(n, m, x, y - 1, d[x][y] + 1);
    CheckAndPush(n, m, x, y + 1, d[x][y] + 1);
  }

  return -1;
}

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    printf("%d\n", Solve());
  }
  return 0;
}