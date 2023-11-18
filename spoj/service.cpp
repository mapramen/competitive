#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int, int>
#define pll pair<ll, ll>
#define N 201
#define M 1001
#define INF 1E9

int a[M], cost[N][N], dp_cur[N][N], dp_next[N][N];

void Reset(int n, int dp[N][N]) {
  for (int y = 1; y <= n; ++y) {
    for (int z = 1; z <= n; ++z) {
      dp[y][z] = INF;
    }
  }
}

void Update(int i, int x, int y, int z, int val) {
  if (x == y || x == z || y == z) {
    return;
  }
  if (dp_next[y][z] > val) {
    dp_next[y][z] = val;
  }
}

int Solve() {
  int n, m;
  scanf("%d%d", &n, &m);

  for (int y = 1; y <= n; ++y) {
    for (int z = 1; z <= n; ++z) {
      scanf("%d", &cost[y][z]);
    }
  }

  for (int i = 1; i <= m; ++i) {
    scanf("%d", &a[i]);
  }

  Reset(n, dp_cur);

  a[0] = 1;
  dp_cur[2][3] = 0;

  for (int i = 1; i <= m; ++i) {
    Reset(n, dp_next);

    for (int x = a[i - 1], nx = a[i], y = 1; y <= n; ++y) {
      for (int z = 1; z <= n; ++z) {
        if (dp_cur[y][z] == INF) {
          continue;
        }
        Update(i, nx, y, z, dp_cur[y][z] + cost[x][nx]);
        Update(i, nx, x, z, dp_cur[y][z] + cost[y][nx]);
        Update(i, nx, x, y, dp_cur[y][z] + cost[z][nx]);
      }
    }

    for (int y = 1; y <= n; ++y) {
      for (int z = 1; z <= n; ++z) {
        dp_cur[y][z] = dp_next[y][z];
      }
    }
  }

  int ans = INF;
  for (int y = 1; y <= n; ++y) {
    for (int z = 1; z <= n; ++z) {
      ans = min(ans, dp_cur[y][z]);
    }
  }
  return ans;
}

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    printf("%d\n", Solve());
  }
  return 0;
}