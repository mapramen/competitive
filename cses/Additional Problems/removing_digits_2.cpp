#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int, int>
#define pll pair<ll, ll>
#define pli pair<ll, int>

map<pli, pli> dp;

pli DP(ll n, int max_digit) {
  if (n == 0) {
    return {max_digit != 0, -max_digit};
  }

  if (n < 10) {
    n -= max(max_digit, (int)n);
    if (n < 0) {
      return {1, n};
    }

    if (max_digit == 0) {
      return {1, 0};
    }

    return {2, -max_digit};
  }

  auto it = dp.find({n, max_digit});
  if (it != dp.end()) {
    return it->second;
  }

  ll p = 1;
  while (n / p >= 10) {
    p *= 10;
  }

  ll cnt = 0;
  int residue = 0;

  for (ll i = n / p, remainder = n % p; i >= 0; --i) {
    auto [cnti, residuei] = DP(remainder, max(max_digit, (int)i));
    cnt += cnti;
    residue = residuei;
    remainder = p + residue;
  }

  return dp[{n, max_digit}] = {cnt, residue};
}

int main() {
  ll n;
  scanf("%lld", &n);

  auto [cnt, _] = DP(n, 0);
  printf("%lld\n", cnt);

  return 0;
}