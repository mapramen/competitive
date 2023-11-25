#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int, int>
#define pll pair<ll, ll>
#define N 50

char a[N][N], color[10];
int d[N][N][N];
queue<tuple<int, int, int>> Q;

void CheckAndPush(int x, int y, int z, int nx, int dis) {
  if (a[x][nx] != a[y][z] || d[nx][y][z] != INT_MAX) {
    return;
  }

  d[nx][y][z] = dis;
  Q.push(make_tuple(nx, y, z));
}

int Solve() {
  int n;
  scanf("%d", &n);

  if (n == 0) {
    exit(0);
  }

  int p1, p2, p3;
  scanf("%d%d%d", &p1, &p2, &p3);
  --p1, --p2, --p3;

  for (int x = 0; x < n; ++x) {
    for (int y = 0; y < n; ++y) {
      scanf("%s", color);
      a[x][y] = color[0];
    }
  }

  for (int x = 0; x < n; ++x) {
    for (int y = 0; y < n; ++y) {
      for (int z = 0; z < n; ++z) {
        d[x][y][z] = INT_MAX;
      }
    }
  }

  while (!Q.empty()) {
    Q.pop();
  }

  d[p1][p2][p3] = 0;
  Q.push(make_tuple(p1, p2, p3));

  while (!Q.empty()) {
    auto [x, y, z] = Q.front();
    Q.pop();

    if (x == y && y == z) {
      return d[x][y][z];
    }

    int dis = 1 + d[x][y][z];

    for (int nx = 0; nx < n; ++nx) {
      CheckAndPush(x, y, z, nx, dis);
      CheckAndPush(y, x, z, nx, dis);
      CheckAndPush(z, x, y, nx, dis);
    }
  }

  return -1;
}

int main() {
  while (true) {
    int ans = Solve();
    if (ans == -1) {
      printf("impossible\n");
    } else {
      printf("%d\n", ans);
    }
  }
  return 0;
}