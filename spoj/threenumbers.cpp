#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int, int>
#define pll pair<ll, ll>

ll GetCount(int a, int b, ll m) {
  return m / a + m / b - m / (a * b / __gcd(a, b));
}

ll BinarySearch(int n, int a, int b) {
  ll x = 0, y = 1E18, ans = y;
  while (x <= y) {
    ll mid = x + (y - x) / 2;
    if (GetCount(a, b, mid) >= n) {
      ans = mid, y = mid - 1;
    } else {
      x = mid + 1;
    }
  }
  return ans;
}

ll Solve() {
  int a, b, n;
  scanf("%d%d%d", &a, &b, &n);
  return BinarySearch(n, a, b);
}

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    printf("%lld\n", Solve());
  }
  return 0;
}