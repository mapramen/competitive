#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int, int>
#define pll pair<ll, ll>
#define MOD 1000000009

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

pll Solve() {
  int n;
  scanf("%d", &n);

  ll positive_num_sum = 0;
  int max_negative_num = INT_MIN;
  int zero_cnt = 0;

  while (n--) {
    int x;
    scanf("%d", &x);

    if (x > 0) {
      positive_num_sum += x;
      continue;
    }

    if (x < 0) {
      max_negative_num = max(max_negative_num, x);
      continue;
    }

    ++zero_cnt;
  }

  if (positive_num_sum > 0) {
    return {positive_num_sum, ModularExponentation(2, zero_cnt)};
  }

  if (zero_cnt > 0) {
    return {0, (ModularExponentation(2, zero_cnt) + MOD - 1) % MOD};
  }

  return {max_negative_num, 1};
}

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    auto [x, y] = Solve();
    printf("%lld %lld\n", x, y);
  }
  return 0;
}