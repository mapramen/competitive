#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int, int>
#define pll pair<ll, ll>

ll GetCount(int n) {
  return (1ll * n * n + n + 2) / 2;
}

int BinarySearch(ll n) {
  int x = 0, y = 1E6, ans = -1;
  while (x <= y) {
    int mid = x + (y - x) / 2;
    if (GetCount(mid) < n) {
      x = mid + 1, ans = mid;
    } else {
      y = mid - 1;
    }
  }
  return ans + 1;
}

int Solve() {
  ll n;
  scanf("%lld", &n);
  return BinarySearch(n);
}

int main() {
  int t;
  scanf("%d", &t);
  for (int k = 1; k <= t; ++k) {
    printf("%d\n", Solve());
  }
  return 0;
}