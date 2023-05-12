#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int, int>
#define pll pair<ll, ll>

int SolvePowerOfTwo(int n, int k) {
  if (n == 1) {
    return 0;
  }

  return 2 * k <= n ? 2 * k - 1 : 2 * SolvePowerOfTwo(n / 2, k - n / 2);
}

int Solve(int n, int k) {
  if ((n & (n - 1)) == 0) {
    return SolvePowerOfTwo(n, k);
  }

  if (2 * k <= n) {
    return 2 * k - 1;
  }

  int m = 1;
  while (m <= n) {
    m *= 2;
  }
  m /= 2;

  int r = n - m;

  int x = Solve(m, k - r);
  if (x < n - 2 * r) {
    return 2 * r + x;
  }

  x -= n - 2 * r;
  return 2 * x;
}

int Solve() {
  int n, k;
  scanf("%d%d", &n, &k);
  return Solve(n, k) + 1;
}

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    printf("%d\n", Solve());
  }
  return 0;
}