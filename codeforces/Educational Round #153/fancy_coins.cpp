#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int, int>
#define pll pair<ll, ll>

int Solve() {
  int m, k, a1, ak;
  scanf("%d%d%d%d", &m, &k, &a1, &ak);

  int xk = min(ak, m / k);
  m -= xk * k;
  ak -= xk;

  int x1 = min(a1, m);
  m -= x1;
  a1 -= x1;

  int yk = m / k;
  int y1 = m % k;

  int ans = y1 + yk;
  if (y1 > 1 && x1 + y1 >= k) {
    ++yk;
    x1 -= (k - y1);
    y1 = 0;
  }

  ans = min(ans, y1 + yk);
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