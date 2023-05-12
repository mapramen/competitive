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

int ModularInverse(int a) {
  return ModularExponentation(a, MOD - 2);
}

int main() {
  int n, m;
  scanf("%d%d", &n, &m);

  vector<int> divisors;
  for (int i = 1; i <= n; ++i) {
    if (n % i == 0) {
      divisors.push_back(i);
    }
  }

  vector<int> c(divisors.size());
  for (int i = 0; i < divisors.size(); ++i) {
    c[i] = ModularExponentation(m, divisors[i]);
  }

  for (int i = 0; i < divisors.size(); ++i) {
    for (int j = 0; j < i; ++j) {
      if (divisors[i] % divisors[j] == 0) {
        c[i] = (c[i] + MOD - c[j]) % MOD;
      }
    }
  }

  int ans = 0;
  for (int i = 0; i < divisors.size(); ++i) {
    ans = (ans + 1ll * c[i] * ModularInverse(divisors[i])) % MOD;
  }

  printf("%d\n", ans);

  return 0;
}