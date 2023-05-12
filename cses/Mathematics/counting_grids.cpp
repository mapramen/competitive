#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int, int>
#define pll pair<ll, ll>
#define MOD 1000000007

int ModularExponentation(int a, ll n) {
  int ans = 1;
  for (; n > 0; n /= 2) {
    if (n % 2 == 1) {
      ans = (1ll * ans * a) % MOD;
    }
    a = (1ll * a * a) % MOD;
  }
  return ans;
}

int ModularInverse(int a) {
  return ModularExponentation(a, MOD - 2);
}

int main() {
  int n;
  scanf("%d", &n);

  int c0 = ModularExponentation(2, 1ll * n * n);
  int c1 = ModularExponentation(2, (1ll * n * n + 3 * (n % 2)) / 4);
  int c2 = ModularExponentation(2, (1ll * n * n + n % 2) / 2);

  c2 = (c2 + MOD - c1) % MOD;
  c0 = (0ll + c0 + (MOD - c1) + (MOD - c2)) % MOD;

  int ans = (1ll * c0 * ModularInverse(4) + c1 + 1ll * c2 * ModularInverse(2)) % MOD;
  printf("%d\n", ans);

  return 0;
}