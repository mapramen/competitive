#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int, int>
#define pll pair<ll, ll>

int ModularExponentation(int a, int n, int mod) {
  int ans = 1;
  for (; n > 0; n /= 2) {
    if (n % 2 == 1) {
      ans = (1ll * ans * a) % mod;
    }
    a = (1ll * a * a) % mod;
  }
  return ans;
}

int DiscreteLogarithm(int a, int b, int m) {
  if (a == 0) {
    // NOTE: HANDLE THIS CASE ACCORDING TO THE PROBLEM
    return INT_MIN;
  }

  a %= m, b %= m;

  int k = 1, add = 0;
  for (int g = __gcd(a, m); g > 1; g = __gcd(a, m)) {
    if (b == k) {
      return add;
    }

    if (b % g != 0) {
      return -1;
    }

    b /= g, m /= g, ++add;
    k = (k * 1ll * a / g) % m;
  }

  int n = sqrt(m) + 1;

  unordered_map<int, int> vals;
  for (int q = 0, cur = b; q <= n; ++q) {
    vals[cur] = q;
    cur = (cur * 1ll * a) % m;
  }

  for (int p = 1, cur = k, an = ModularExponentation(a, n, m); p <= n; ++p) {
    cur = (cur * 1ll * an) % m;

    auto it = vals.find(cur);
    if (it != vals.end()) {
      return n * p - it->second + add;
    }
  }

  return -1;
}

int Solve() {
  int a, b, m;
  scanf("%d%d%d", &a, &m, &b);
  if (a == 0 && b == 0 && m == 0) {
    exit(0);
  }
  return DiscreteLogarithm(a, b, m);
}

int main() {
  while (true) {
    int ans = Solve();
    printf("%s\n", ans < 0 ? "No Solution" : to_string(ans).c_str());
  }
  return 0;
}