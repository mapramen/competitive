#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int, int>
#define pll pair<ll, ll>
#define N 1001

bool blocked[N][N], attacked[N][N];
vector<pii> queen_directions = {{-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1}};
vector<pii> knight_moves = {{-2, -1}, {-2, 1}, {-1, -2}, {-1, 2}, {1, -2}, {1, 2}, {2, -1}, {2, 1}};

void Reset(int n, int m) {
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      blocked[i][j] = attacked[i][j] = false;
    }
  }
}

vector<pii> ReadPositions() {
  int n;
  scanf("%d", &n);

  vector<pii> positions(n);
  for (auto& p : positions) {
    scanf("%d%d", &p.first, &p.second);
    --p.first, --p.second;
    blocked[p.first][p.second] = true;
  }

  return positions;
}

int Solve() {
  int n, m;
  scanf("%d%d", &n, &m);

  if (n == 0 && m == 0) {
    exit(0);
  }

  Reset(n, m);

  vector<pii> queens = ReadPositions();
  vector<pii> knights = ReadPositions();
  vector<pii> pawns = ReadPositions();

  for (auto [x, y] : queens) {
    for (auto [dx, dy] : queen_directions) {
      for (int nx = x + dx, ny = y + dy; nx >= 0 && nx < n && ny >= 0 && ny < m && !blocked[nx][ny]; nx += dx, ny += dy) {
        attacked[nx][ny] = true;
      }
    }
  }

  for (auto [x, y] : knights) {
    for (auto [dx, dy] : knight_moves) {
      int nx = x + dx, ny = y + dy;
      if (nx >= 0 && nx < n && ny >= 0 && ny < m) {
        attacked[nx][ny] = true;
      }
    }
  }

  int ans = 0;
  for (int x = 0; x < n; ++x) {
    for (int y = 0; y < m; ++y) {
      ans += !attacked[x][y] && !blocked[x][y];
    }
  }

  return ans;
}

int main() {
  for (int k = 1;; ++k) {
    printf("Board %d has %d safe squares.\n", k, Solve());
  }
  return 0;
}