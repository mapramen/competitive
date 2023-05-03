#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int, int>
#define pll pair<ll, ll>

int main() {
  int n, m;
  scanf("%d%d", &n, &m);

  vector<ll> a(n);
  for (ll& x : a) {
    scanf("%lld", &x);
  }
  sort(a.begin(), a.end(), greater<ll>());

  ll ans = m == n || a[m - 1] != a[m] ? a[m - 1] : -1;
  printf("%lld\n", ans);

  return 0;
}