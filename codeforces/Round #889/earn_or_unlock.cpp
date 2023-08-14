#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int, int>
#define pll pair<ll, ll>
#define N 200001

int a[N];
bitset<N> dp;

int main() {
  int n;
  scanf("%d", &n);

  for (int i = 1; i <= n; ++i) {
    scanf("%d", &a[i]);
  }

  dp.set(1);

  ll s = 0, ans = 0;
  for (int i = 1; i <= 2 * n; ++i) {
    s += a[i];
    if (dp.test(i)) {
      ans = max(ans, s - i + 1);
    }
    dp |= (dp << a[i]);
    dp.reset(i);
  }

  printf("%lld\n", ans);

  return 0;
}