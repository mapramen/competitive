#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int, int>
#define pll pair<ll, ll>

ll Solve() {
  ll n;
  if (scanf("%lld", &n) == EOF) {
    exit(0);
  }

  ll m = n / 9, k = n % 9;
  return 81 * m + k * k;
}

int main() {
  while (true) {
    printf("%lld\n", Solve());
  }
  return 0;
}