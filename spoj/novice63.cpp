#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int, int>
#define pll pair<ll, ll>
#define N 61

ll c[N][N], ans[N];

void Initialize() {
  for (int i = 0; i < N; ++i) {
    c[i][0] = 1;
    for (int j = 1; j <= i; ++j) {
      c[i][j] = c[i - 1][j - 1] + c[i - 1][j];
    }
  }

  for (int i = 2; i < N; i += 2) {
    ans[i] = c[i - 1][i / 2];
  }

  for (int i = 1; i < N; ++i) {
    ans[i] += ans[i - 1];
  }

  ans[1] = 1;
}

ll Solve() {
  ll n;
  scanf("%lld", &n);
  int k = __builtin_ctzll(n);
  return ans[k];
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