#include <bits/stdc++.h>
#pragma GCC target("popcnt")

using namespace std;

typedef long long ll;

#define pii pair<int, int>
#define pll pair<ll, ll>
#define N 3000

bitset<N> a[N];

int main() {
  int n;
  scanf("%d", &n);

  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }

  ll ans = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < i; ++j) {
      int cnt = (a[i] & a[j]).count();
      ans += (cnt * (cnt - 1)) / 2;
    }
  }

  printf("%lld\n", ans);

  return 0;
}