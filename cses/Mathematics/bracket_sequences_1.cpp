#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int, int>
#define pll pair<ll, ll>
#define N 1000001
#define MOD 1000000007

int fact[N], inv_fact[N];

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

int ModularInverse(int a) {
  return ModularExponentation(a, MOD - 2);
}

void Initialize() {
  fact[0] = 1;
  for (int i = 1; i < N; ++i) {
    fact[i] = (1ll * i * fact[i - 1]) % MOD;
  }

  inv_fact[N - 1] = ModularInverse(fact[N - 1]);
  for (int i = N - 2; i > -1; --i) {
    inv_fact[i] = (1ll * (i + 1) * inv_fact[i + 1]) % MOD;
  }
}

int nCr(int n, int r) {
  if (n < 0 || r < 0 || n < r) {
    return 0;
  }

  int q = (1ll * inv_fact[r] * inv_fact[n - r]) % MOD;
  return (1ll * fact[n] * q) % MOD;
}

int Catalan(int n) {
  return (1ll * nCr(2 * n, n) * ModularInverse(n + 1)) % MOD;
}

int main() {
  Initialize();

  int n;
  scanf("%d", &n);

  printf("%d\n", n % 2 == 1 ? 0 : Catalan(n / 2));

  return 0;
}