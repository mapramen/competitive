#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int, int>
#define pll pair<ll, ll>
#define N 501
#define MOD 1000000007

vector<int> GetWays(int m, vector<int>& a) {
  sort(a.begin(), a.end());

  vector<int> dp(m + 1);

  dp[0] = 1;
  for (int x : a) {
    for (int i = m; i > 0; --i) {
      dp[i] = (dp[i] + 1ll * max(0, x - (i - 1)) * dp[i - 1]) % MOD;
    }
  }

  return dp;
}

int main() {
  int n, m;
  scanf("%d%d", &n, &m);

  if (m > 2 * n) {
    printf("0\n");
    return 0;
  }

  vector<int> a, b;
  for (int k = 2; k <= 2 * n; ++k) {
    int cnt = 0;
    for (int x = 1; x <= n; ++x) {
      int y = k - x;
      cnt += (y > 0 && y <= n);
    }
    if (cnt % 2 == 0) {
      a.push_back(cnt);
    } else {
      b.push_back(cnt);
    }
  }

  vector<int> dp1 = GetWays(m, a);
  vector<int> dp2 = GetWays(m, b);

  int ans = 0;
  for (int i = 0; i <= m; ++i) {
    ans = (ans + 1ll * dp1[i] * dp2[m - i]) % MOD;
  }

  printf("%d\n", ans);

  return 0;
}