#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int, int>
#define pll pair<ll, ll>
#define N 1001

int dp[N][N];

int main() {
  string A, B;
  cin >> A >> B;

  int n = A.size(), m = B.size();

  dp[0][0] = 0;
  for (int j = 1; j <= m; ++j) {
    dp[0][j] = n;
  }

  for (int i = 1; i <= n; ++i) {
    dp[i][0] = 1;
    for (int j = 1, k = 0; j <= m; ++j) {
      if (B[j - 1] == A[i - 1]) {
        k = j;
      }

      if (k == 0) {
        dp[i][j] = 1;
        continue;
      }

      dp[i][j] = min(dp[i - 1][j], 1 + dp[i - 1][k - 1]);
    }
  }

  printf("%d\n", dp[n][m]);

  return 0;
}