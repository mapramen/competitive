#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int, int>
#define pll pair<ll, ll>
#define N 200001

int dp[N];

void Reset(int n) {
  for (int i = 1; i <= n; ++i) {
    dp[i] = INT_MIN;
  }
}

int Solve() {
  int n;
  scanf("%d", &n);

  Reset(n);

  int ans = 0;
  for (int i = 1; i <= n; ++i) {
    int x;
    scanf("%d", &x);

    int ansx = i + dp[x];
    dp[x] = max(dp[x], ans - (i - 1));
    ans = max(ans, ansx);
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