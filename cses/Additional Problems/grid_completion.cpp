#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int, int>
#define pll pair<ll, ll>
#define N 501
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

char s[N][N];
int A[N], B[N], posA[N], posB[N];

int main() {
  Initialize();

  int n;
  scanf("%d", &n);

  for (int x = 0; x < n; ++x) {
    scanf("%s", s[x]);
  }

  for (int x = 0; x < n; ++x) {
    for (int y = 0; y < n; ++y) {
      if (s[x][y] == 'A') {
        A[x + 1] = y + 1;
      }

      if (s[x][y] == 'B') {
        B[x + 1] = y + 1;
      }
    }
  }

  for (int i = 1; i <= n; ++i) {
    posA[A[i]] = i;
    posB[B[i]] = i;
  }
  posA[0] = 0, posB[0] = 0;

  int a = 0, b = 0, c = 0, d = 0, p = 0, q = 0;
  for (int i = 1; i <= n; ++i) {
    a += (A[i] != 0 && B[i] == 0 && posB[A[i]] == 0);
    b += (B[i] != 0 && A[i] == 0 && posA[B[i]] == 0);
    c += (A[i] == 0 && B[i] == 0);
    d += (posA[i] == 0 && posB[i] == 0);
    p += (A[i] == 0);
    q += (B[i] == 0);
  }

  int ans = 0;
  for (int i = 0; i <= a; ++i) {
    for (int j = 0; j <= b; ++j) {
      for (int k = 0; k <= min(c, d); ++k) {
        int ansx = 1;
        ansx = (1ll * ansx * nCr(a, i)) % MOD;
        ansx = (1ll * ansx * nCr(b, j)) % MOD;
        ansx = (1ll * ansx * nCr(c, k)) % MOD;
        ansx = (1ll * ansx * nCr(d, k)) % MOD;
        ansx = (1ll * ansx * fact[k]) % MOD;
        ansx = (1ll * ansx * fact[p - j - k]) % MOD;
        ansx = (1ll * ansx * fact[q - i - k]) % MOD;
        ans = (ans + ((i + j + k) % 2 == 0 ? ansx : MOD - ansx)) % MOD;
      }
    }
  }

  printf("%d\n", ans);

  return 0;
}