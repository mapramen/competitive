#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int, int>
#define pll pair<ll, ll>
#define MOD 1000000007

int ModularExponentation(int a, int n) {
  int ans = 1;
  for (; n > 0; n /= 2) {
    if (n % 2 == 1) {
      ans = (1ll * ans * a) % MOD;
    }
    a = (1ll * a * a) % MOD;
  }
  return ans;
}

int Solve() {
  int n;
  scanf("%d", &n);
  --n;

  if (n == 0) {
    return 1;
  }

  return (1ll * (n + 2) * ModularExponentation(2, n - 1)) % MOD;
}

int main() {
  int t;
  scanf("%d", &t);
  for (int k = 1; k <= t; ++k) {
    printf("Case %d: %d\n", k, Solve());
  }
  return 0;
}