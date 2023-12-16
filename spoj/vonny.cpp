#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int, int>
#define pll pair<ll, ll>
#define N 7
#define M 8

int a[N][M];
bool visited[N][M];
int visited_mask;
vector<pii> possible_neighbours{{0, 1}, {1, 0}};
vector<vector<int>> V(N);

void Initialize() {
  for (int i = 0, k = 0; i < N; ++i) {
    V[i].resize(N);
    for (int j = i; j < N; ++j, ++k) {
      V[i][j] = k;
    }
  }
}

int Solve(int x, int y) {
  if (y == M) {
    if (x == N - 1) {
      return 1;
    }
    ++x, y = 0;
  }

  if (visited[x][y]) {
    return Solve(x, y + 1);
  }

  int ans = 0;
  for (auto [dx, dy] : possible_neighbours) {
    int nx = x + dx, ny = y + dy;

    if (nx >= N || ny >= M || visited[nx][ny]) {
      continue;
    }

    int i = a[x][y], j = a[nx][ny];
    if (i > j) {
      swap(i, j);
    }

    int mask = (1 << V[i][j]);

    if ((visited_mask & mask) != 0) {
      continue;
    }

    visited[x][y] = visited[nx][ny] = true;
    visited_mask ^= mask;
    ans += Solve(x, y + 1);
    visited_mask ^= mask;
    visited[x][y] = visited[nx][ny] = false;
  }

  return ans;
}

int Solve() {
  for (int x = 0; x < N; x++) {
    for (int y = 0; y < M; y++) {
      scanf("%d", &a[x][y]);
    }
  }
  return Solve(0, 0);
}

int main() {
  Initialize();

  int t;
  scanf("%d", &t);
  while (t--) {
    printf("%d\n", Solve());
  }

  return 0;
}