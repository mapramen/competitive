#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int, int>
#define pll pair<ll, ll>

int Sqrt(ll n) {
  ll x = max(0.0, sqrt(n) - 1);
  while (x * x <= n) {
    ++x;
  }
  return x - 1;
}

int Solve() {
  ll n;
  scanf("%lld", &n);
  return max(0, Sqrt(n + 1) - 1);
}

int main() {
  int t;
  scanf("%d", &t);
  for (int k = 1; k <= t; ++k) {
    printf("Case %d: %d\n", k, Solve());
  }
  return 0;
}