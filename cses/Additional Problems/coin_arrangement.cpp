#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int, int>
#define pll pair<ll, ll>
#define N 100001

int a[2][N];

int main() {
  int n;
  scanf("%d", &n);

  for (int i = 1; i <= n; ++i) {
    scanf("%d", &a[0][i]);
  }

  for (int i = 1; i <= n; ++i) {
    scanf("%d", &a[1][i]);
  }

  ll ans = 0;
  for (int i = 1, x = 0, y = 0; i <= n; ++i) {
    x += (a[0][i] - 1), y += (a[1][i] - 1);
    if (1ll * x * y < 0) {
      int z = min(abs(x), abs(y));
      x = x < 0 ? x + z : x - z;
      y = y < 0 ? y + z : y - z;
      ans += z;
    }
    ans += abs(x) + abs(y);
  }

  printf("%lld\n", ans);

  return 0;
}