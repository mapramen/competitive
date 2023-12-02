#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int, int>
#define pll pair<ll, ll>
#define N 12
#define B 27

ll dp[N][B], cnt[N];

void Initialize() {
  dp[0][0] = 1;
  for (int i = 1; i < N; ++i) {
    for (int j = 1; j < B; ++j) {
      dp[i][j] = dp[i - 1][j - 1] + j * dp[i - 1][j];
    }
  }

  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < B; ++j) {
      cnt[i] += dp[i][j];
    }
  }
}

ll Solve() {
  int n;
  scanf("%d", &n);
  return cnt[n];
}

int main() {
  Initialize();

  int t;
  scanf("%d", &t);
  while (t--) {
    printf("%lld\n", Solve());
  }
  return 0;
}