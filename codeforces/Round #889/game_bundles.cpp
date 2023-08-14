#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int, int>
#define pll pair<ll, ll>
#define N 60

ll dp[N + 1];

vector<int> Solve(ll m, int k) {
  for (int i = 1; i <= N; ++i) {
    dp[i] = 0;
  }

  dp[0] = 1;
  vector<int> ans;

  for (int i = 1; i <= N; ++i) {
    while (dp[i] <= k * dp[i - 1] && dp[N] + dp[N - i] <= m) {
      for (int j = N; j >= i; --j) {
        dp[j] += dp[j - i];
      }
      ans.push_back(i);
    }
  }

  while (dp[N] < m) {
    ans.push_back(N);
    ++dp[N];
  }

  return ans;
}

int main() {
  ll m;
  scanf("%lld", &m);

  vector<int> ans(N + 1);
  for (int k = 2; k <= 10; ++k) {
    vector<int> ansx = Solve(m, k);
    if (ansx.size() < ans.size()) {
      ans = ansx;
    }
  }

  printf("%lu\n", ans.size());
  for (int x : ans) {
    printf("%d ", x);
  }
  printf("\n");

  return 0;
}