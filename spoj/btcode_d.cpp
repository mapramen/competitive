#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int, int>
#define pll pair<ll, ll>
#define N 101

int A[N][N], B[N][N], C[N][N];

void Read(int n, int m, int a[N][N]) {
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      scanf("%d", &a[i][j]);
    }
  }
}

ll Solve() {
  int n, m;
  scanf("%d%d", &n, &m);

  Read(n, m, A);
  Read(n, m, B);
  Read(n, m, C);

  ll ans = 0;
  for (int i = 1; i <= n; ++i) {
    ll ansx = 0;
    for (int j = 1; j <= m; ++j) {
      ansx = max(ansx, 1ll * min(A[i][j], B[i][j]) * C[i][j]);
    }
    ans += ansx;
  }

  return ans;
}

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    printf("%lld\n", Solve());
  }
  return 0;
}