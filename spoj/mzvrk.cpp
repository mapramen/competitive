#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int, int>
#define pll pair<ll, ll>

ll SumOfWhirligig(ll n) {
  ll ans = 0;
  for (ll p = 1; n > 0; p *= 2, n /= 2) {
    ans += ((n + 1) / 2) * p;
  }
  return ans;
}

ll SumOfWhirligig(ll l, ll r) {
  return SumOfWhirligig(r) - SumOfWhirligig(l - 1);
}

int main() {
  ll l, r;
  scanf("%lld%lld", &l, &r);
  printf("%lld\n", SumOfWhirligig(l, r));
  return 0;
}