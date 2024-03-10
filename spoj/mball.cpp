#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int, int>
#define pll pair<ll, ll>
#define N 100001

ll dp[N];

void Initialize() {
  dp[0] = 1;

  for (int x : {2, 3, 6, 7, 8}) {
    for (int i = x; i < N; ++i) {
      dp[i] += dp[i - x];
    }
  }
}

ll Solve() {
  int n;
  scanf("%d", &n);
  return dp[n];
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