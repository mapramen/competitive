#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int, int>
#define pll pair<ll, ll>
#define N 100001

ll s[N], ss[N];

int main() {
  int n;
  scanf("%d", &n);

  for (int i = 1; i <= n; ++i) {
    int x;
    scanf("%d", &x);
    s[i] = s[i - 1] + x;
    ss[i] = ss[i - 1] + 1ll * x * x;
  }

  int q;
  scanf("%d", &q);

  while (q--) {
    int l, r;
    scanf("%d%d", &l, &r);
    ++l, ++r;

    ll sum = s[r] - s[l - 1];
    ll sqsum = ss[r] - ss[l - 1];

    ll ans = (sum * sum + sqsum) / 2;
    printf("%lld\n", ans);
  }

  return 0;
}