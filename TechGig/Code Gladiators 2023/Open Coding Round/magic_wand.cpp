#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int, int>
#define pll pair<ll, ll>

int main() {
  int n, q;
  scanf("%d%d", &n, &q);

  vector<int> a(n + 1);
  vector<ll> s(n + 1);
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &a[i]);
  }
  sort(a.begin(), a.end());

  for (int i = 1; i <= n; ++i) {
    s[i] = s[i - 1] + a[i];
  }

  while (q--) {
    int x;
    scanf("%d", &x);

    int i = lower_bound(a.begin(), a.end(), x) - a.begin();
    ll ans = (s[n] - 2 * s[i - 1]) - 1ll * (n - 2 * (i - 1)) * x;
    printf("%lld ", ans);
  }
  printf("\n");

  return 0;
}