#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int, int>
#define pll pair<ll, ll>

long double nCr(int n, int r) {
  if (r < 0 || r > n) {
    return 0;
  }

  r = min(r, n - r);

  long double ans = 1;
  for (int i = 1; i <= r; i++) {
    ans *= n - r + i;
    ans /= i;
  }

  return ans;
}

long double Solve() {
  int n;
  scanf("%d", &n);

  long double ans = 1 + n / 9.0 - 1 / nCr(n + 8, 8);
  return ans;
}

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    printf("%.6Lf\n", Solve());
  }
  return 0;
}