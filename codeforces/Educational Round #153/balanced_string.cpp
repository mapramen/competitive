#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int, int>
#define pll pair<ll, ll>
#define N 101
#define M (N * N) / 4

int dp[N][N][M];

void Update(int i, int c0, int c01, int val, char actual, char expected) {
  ++i;
  c01 += expected == '0' ? 0 : c0;
  c0 += (expected == '0');
  val += (actual != expected);
  dp[i][c0][c01] = min(dp[i][c0][c01], val);
}

int main() {
  string s;
  cin >> s;

  int n = s.size();

  int cz = 0;
  for (int i = 0; i < n; ++i) {
    cz += (s[i] == '0');
  }

  int m = cz * (n - cz) / 2;

  for (int i = 0; i <= n; ++i) {
    for (int c0 = 0; c0 <= cz; ++c0) {
      for (int c01 = 0; c01 <= m; ++c01) {
        dp[i][c0][c01] = INT_MAX;
      }
    }
  }

  dp[0][0][0] = 0;
  for (int i = 0; i < n; ++i) {
    for (int c0 = 0; c0 <= cz; ++c0) {
      for (int c01 = 0; c01 <= m; ++c01) {
        if (dp[i][c0][c01] == INT_MAX) {
          continue;
        }
        Update(i, c0, c01, dp[i][c0][c01], s[i], '0');
        Update(i, c0, c01, dp[i][c0][c01], s[i], '1');
      }
    }
  }

  printf("%d\n", dp[n][cz][m] / 2);

  return 0;
}