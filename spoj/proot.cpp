#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int, int>
#define pll pair<ll, ll>

vector<int> GetPrimeDivisors(int n) {
  vector<int> ans;
  for (int i = 2; i * i <= n; ++i) {
    if (n % i != 0) {
      continue;
    }

    ans.push_back(i);
    while (n % i == 0) {
      n /= i;
    }
  }

  if (n > 1) {
    ans.push_back(n);
  }

  return ans;
}

int ModularExponentation(int a, int n, int mod) {
  int ans = 1 % mod;
  for (a %= mod; n > 0; n /= 2) {
    if (n % 2 == 1) {
      ans = (1ll * ans * a) % mod;
    }
    a = (1ll * a * a) % mod;
  }
  return ans % mod;
}

void Solve() {
  int n, q;
  scanf("%d%d", &n, &q);
  if (n == 0 && q == 0) {
    exit(0);
  }

  int phi = n - 1;
  vector<int> prime_divisors = GetPrimeDivisors(phi);

  while (q--) {
    int g;
    scanf("%d", &g);
    g %= n;

    bool is_primitive_root = __gcd(g, n) == 1;
    for (int p : prime_divisors) {
      if (ModularExponentation(g, phi / p, n) == 1) {
        is_primitive_root = false;
      }

      if (!is_primitive_root) {
        break;
      }
    }

    printf("%s\n", is_primitive_root ? "YES" : "NO");
  }
}

int main() {
  while (true) {
    Solve();
  }
  return 0;
}