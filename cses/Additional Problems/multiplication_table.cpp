#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int, int>
#define pll pair<ll, ll>

ll GetCount(int n, ll m) {
  ll cnt = 0;
  for (int i = 1; i <= n; ++i) {
    cnt += min((ll)n, m / i);
  }
  return cnt;
}

ll BinarySearch(int n, ll r) {
  ll x = 0, y = 1ll * n * n, ans = 0;
  while (x <= y) {
    ll mid = (x + y) / 2;
    if (GetCount(n, mid) < r) {
      ans = mid, x = mid + 1;
    } else {
      y = mid - 1;
    }
  }
  return 1 + ans;
}

int main() {
  int n;
  scanf("%d", &n);
  printf("%lld\n", BinarySearch(n, (1ll * n * n + 1) / 2));
  return 0;
}