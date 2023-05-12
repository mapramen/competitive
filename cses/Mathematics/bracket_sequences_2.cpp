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

int Solve() {
  int n;
  scanf("%d", &n);

  string s;
  cin >> s;

  int m = 0;
  for (int i = 0; i < s.size(); ++i) {
    m += (s[i] == '(' ? 1 : -1);
    if (m < 0) {
      return 0;
    }
  }

  n -= s.size();
  if (n < m || (n - m) % 2 == 1) {
    return 0;
  }

  int ans = nCr(n + 1, (n - m) / 2);
  ans = (1ll * (m + 1) * ans) % MOD;
  ans = (1ll * ans * ModularInverse(n + 1)) % MOD;

  return ans;
}

int main() {
  Initialize();
  printf("%d\n", Solve());
  return 0;
}