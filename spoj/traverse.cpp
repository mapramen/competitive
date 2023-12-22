#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int, int>
#define pll pair<ll, ll>

int main() {
  int n;
  scanf("%d", &n);

  vector<string> s(n);
  for (int i = 0; i < n; ++i) {
    cin >> s[i];
  }

  vector<vector<int>> dp(n, vector<int>(n, 0));

  dp[n - 1][n - 1] = 1;
  for (int i = n - 1; i > -1; --i) {
    for (int j = n - 1; j > -1; --j) {
      if (i == n - 1 && j == n - 1) {
        continue;
      }

      int d = s[i][j] - '0';
      if (i + d < n) {
        dp[i][j] += dp[i + d][j];
      }

      if (j + d < n) {
        dp[i][j] += dp[i][j + d];
      }
    }
  }

  printf("%d", dp[0][0]);

  return 0;
}