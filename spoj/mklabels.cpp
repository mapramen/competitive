#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int, int>
#define pll pair<ll, ll>

int ModularExponentation(int a, int n) {
  int ans = 1;
  for (; n > 0; n /= 2) {
    if (n % 2 == 1) {
      ans = (1ll * ans * a);
    }
    a = (1ll * a * a);
  }
  return ans;
}

int main() {
  for (int k = 1;; ++k) {
    int n;
    scanf("%d", &n);
    if (n == 0) {
      break;
    }
    printf("Case %d, N = %d, # of different labelings = %d\n", k, n, ModularExponentation(n, n - 2));
  }
  return 0;
}