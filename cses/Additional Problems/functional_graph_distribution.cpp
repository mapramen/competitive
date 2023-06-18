#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int, int>
#define pll pair<ll, ll>
#define N 5001
#define MOD 1000000007

// Stirling numbers of the first kind
int S1[N][N];

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

  S1[0][0] = 1;
  for (int i = 1; i < N; ++i) {
    for (int j = 1; j <= i; ++j) {
      S1[i][j] = (1ll * (i - 1) * S1[i - 1][j] + S1[i - 1][j - 1]) % MOD;
    }
  }
}

int nCr(int n, int r) {
  if (n < 0 || r < 0 || n < r) {
    return 0;
  }

  int q = (1ll * inv_fact[r] * inv_fact[n - r]) % MOD;
  return (1ll * fact[n] * q) % MOD;
}

int Stirling1(int n, int k) {
  if (n < 0 || k < 0 || n < k) {
    return 0;
  }

  return S1[n][k];
}

int main() {
  Initialize();

  int n;
  scanf("%d", &n);

  for (int k = 1; k <= n; ++k) {
    int ans = 0;
    for (int i = n - 1, mul = 1; i >= k - 1; --i, mul = (1ll * mul * n) % MOD) {
      int ansx = mul;
      ansx = (1ll * ansx * nCr(n - 1, i)) % MOD;
      ansx = (1ll * ansx * Stirling1(i + 1, k)) % MOD;
      ans = (ans + ansx) % MOD;
    }
    printf("%d\n", ans);
  }

  return 0;
}