#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int, int>
#define pll pair<ll, ll>
#define MOD 998244353
#define B 29

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

long long Solve(int k, vector<int>& a) {
  if (a.empty()) {
    return 0;
  }

  if (k == -1) {
    return 1ll * a.size() * a.size();
  }

  vector<int> zeros, ones;
  for (int x : a) {
    if (x & (1 << k)) {
      ones.push_back(x);
    } else {
      zeros.push_back(x);
    }
  }

  ll ans = 3ll * zeros.size() * ones.size();
  ans += Solve(k - 1, zeros);
  ans += 1ll * ones.size() * ones.size() + Solve(k - 1, ones);

  return ans;
}

int Solve() {
  int n;
  scanf("%d", &n);

  vector<int> a(n);
  for (int& x : a) {
    scanf("%d", &x);
  }

  ll ans = Solve(B, a) % MOD;
  ans = (ans * ModularInverse(n)) % MOD;
  ans = (ans * ModularInverse(n)) % MOD;

  return ans;
}

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    printf("%d\n", Solve());
  }
  return 0;
}