#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int, int>
#define pll pair<ll, ll>
#define MOD 1000000007

int ModularExponentation(int a, int n, int mod) {
  int ans = 1;
  for (; n > 0; n /= 2) {
    if (n % 2 == 1) {
      ans = (1ll * ans * a) % mod;
    }
    a = (1ll * a * a) % mod;
  }
  return ans % mod;
}

int ModularInverse(int a, int mod) {
  return ModularExponentation(a, mod - 2, mod);
}

int NumberOfDivisors(vector<pii>& a) {
  int ans = 1;
  for (pii& p : a) {
    ans = (1ll * ans * (1 + p.second)) % MOD;
  }
  return ans;
}

int SumOfDivisors(vector<pii>& a) {
  int ans = 1;
  for (pii& p : a) {
    ans = (1ll * ans * (ModularExponentation(p.first, p.second + 1, MOD) + MOD - 1)) % MOD;
    ans = (1ll * ans * ModularInverse(p.first - 1, MOD)) % MOD;
  }
  return ans;
}

int ProductOfDivisors(vector<pii>& a) {
  bool need_to_square_root = true;

  int pwr = 1;
  for (pii& p : a) {
    if (need_to_square_root && p.second % 2 == 1) {
      pwr = (1ll * pwr * ((1 + p.second) / 2)) % (MOD - 1);
      need_to_square_root = false;
    } else {
      pwr = (1ll * pwr * (1 + p.second)) % (MOD - 1);
    }
  }

  int ans = 1;
  for (pii& p : a) {
    ans = (1ll * ans * ModularExponentation(p.first, p.second / (1 + need_to_square_root), MOD)) % MOD;
  }
  ans = ModularExponentation(ans, pwr, MOD);
  return ans;
}

int main() {
  int n;
  scanf("%d", &n);

  vector<pii> a(n);
  for (pii& p : a) {
    scanf("%d%d", &p.first, &p.second);
  }

  printf("%d %d %d\n", NumberOfDivisors(a), SumOfDivisors(a), ProductOfDivisors(a));

  return 0;
}