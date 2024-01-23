#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int, int>
#define pll pair<ll, ll>

ll Solve() {
  int n;
  scanf("%d", &n);

  vector<ll> a(n);
  for (ll& x : a) {
    scanf("%lld", &x);
  }

  ll sum = 0;
  for (ll x : a) {
    sum += x;
  }

  if (sum % (n - 1) != 0) {
    return -1;
  }

  sum /= n - 1;

  if (sum > n) {
    return -1;
  }

  for (ll& x : a) {
    if (x > sum) {
      return -1;
    }
    x = sum - x;
  }

  for (ll x : a) {
    sum -= x;
  }

  if (sum != 0) {
    return -1;
  }

  for (ll x : a) {
    sum += x;
  }

  return sum;
}

int main() {
  int t = 1;
  while (t--) {
    printf("%lld\n", Solve());
  }
  return 0;
}