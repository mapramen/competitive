#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int, int>
#define pll pair<ll, ll>
#define MOD 1000000007

ll Ceil(ll a, ll b) {
  return (a + b - 1) / b;
}

int Solve() {
  ll n;
  scanf("%lld", &n);
  return Ceil(2 * n, 3) % MOD;
}

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    printf("%d\n", Solve());
  }
  return 0;
}