#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int, int>
#define pll pair<ll, ll>
#define N 1000001

int dp[N];

void Initialize() {
  for (int i = 0; i < N; ++i) {
    dp[i] = INT_MIN;
  }

  for (int i = 8; i < N; ++i) {
    int ans = INT_MIN;
    if ((i - 5) % 3 == 0) {
      ans = max(ans, i - 5);
    }

    if ((i - 3) % 5 == 0) {
      ans = 3;
    }

    ans = max(ans, 3 + dp[i - 3]);
    ans = max(ans, dp[i - 5]);

    dp[i] = ans;
  }
}

int Solve() {
  int n;
  scanf("%d", &n);
  return dp[n] <= 0 ? -1 : dp[n];
}

int main() {
  Initialize();
  int t;
  scanf("%d", &t);
  for (int k = 1; k <= t; ++k) {
    printf("Case %d: %d\n", k, Solve());
  }
  return 0;
}