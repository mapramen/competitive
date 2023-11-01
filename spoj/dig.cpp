#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int, int>
#define pll pair<ll, ll>
#define MOD 1000000007

int nCr(int n, int r) {
  if (n < 0 || r < 0 || n < r) {
    return 0;
  }

  vector<int> v;
  for (int i = 0; i < r; ++i) {
    v.push_back(n - i);
  }

  for (int i = 2; i <= r; ++i) {
    int j = i;
    for (int& x : v) {
      int g = __gcd(x, j);
      x /= g;
      j /= g;
    }
  }

  int ans = 1;
  for (int& x : v) {
    ans = (1ll * ans * x) % MOD;
  }

  return ans;
}

int Solve() {
  int n;
  scanf("%d", &n);
  return nCr(n, 4);
}

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    printf("%d\n", Solve());
  }
  return 0;
}