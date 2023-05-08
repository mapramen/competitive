#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int, int>
#define pll pair<ll, ll>
#define N 200001

ll a[N];

int main() {
  int n;
  scanf("%d", &n);

  for (int i = 1; i <= n; ++i) {
    int x;
    scanf("%d", &x);
    a[i] -= x;
  }

  for (int i = 1; i <= n; ++i) {
    int x;
    scanf("%d", &x);
    a[i] += x;
  }

  for (int i = 1; i <= n; ++i) {
    a[i] += a[i - 1];
  }

  sort(a, a + n);

  ll m = a[(n + 1) / 2 - 1];

  ll ans = 0;
  for (int i = 0; i < n; ++i) {
    ans += abs(a[i] - m);
  }
  printf("%lld\n", ans);

  return 0;
}