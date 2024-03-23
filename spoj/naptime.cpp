#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int, int>
#define pll pair<ll, ll>
#define N 3831

int u[N];
int dp[2][N];

void Reset(int m) {
  for (int j = 0; j <= m; ++j) {
    dp[0][j] = INT_MIN;
    dp[1][j] = INT_MIN;
  }
}

int Solve() {
  int n, m;
  scanf("%d%d", &n, &m);

  for (int i = 1; i <= n; ++i) {
    scanf("%d", &u[i]);
  }

  Reset(m);

  dp[0][0] = 0;
  for (int i = 1; i <= n; ++i) {
    for (int j = m; j >= 0; --j) {
      dp[0][j] = max(dp[0][j], dp[1][j]);
      if (j != 0) {
        dp[1][j] = max(dp[0][j - 1], dp[1][j - 1] + u[i]);
      }
    }
  }

  int ans = INT_MIN;
  for (int j = 0; j <= m; ++j) {
    ans = max(ans, dp[0][j]);
    ans = max(ans, dp[1][j]);
  }

  Reset(m);
  dp[1][1] = u[1];
  for (int i = 2; i <= n; ++i) {
    for (int j = m; j >= 0; --j) {
      dp[0][j] = max(dp[0][j], dp[1][j]);
      if (j != 0) {
        dp[1][j] = max(dp[0][j - 1], dp[1][j - 1] + u[i]);
      }
    }
  }

  for (int j = 0; j <= m; ++j) {
    ans = max(ans, dp[1][j]);
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