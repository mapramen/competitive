#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int, int>
#define pll pair<ll, ll>

int main() {
  int n, d;
  scanf("%d%d", &n, &d);

  const int M = (1 << d);
  vector<int> a(d), mn(M, INT_MAX), mx(M, INT_MIN);

  while (n--) {
    for (int& x : a) {
      scanf("%d", &x);
    }

    for (int mask = 0; mask < M; ++mask) {
      int val = 0;
      for (int i = 0; i < d; ++i) {
        if ((mask & (1 << i)) != 0) {
          val += a[i];
        } else {
          val -= a[i];
        }
      }
      mn[mask] = min(mn[mask], val);
      mx[mask] = max(mx[mask], val);
    }
  }

  int ans = 0;
  for (int mask = 0; mask < M; ++mask) {
    ans = max(ans, mx[mask] - mn[mask]);
  }

  printf("%d\n", ans);

  return 0;
}