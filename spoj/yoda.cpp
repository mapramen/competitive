#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int, int>
#define pll pair<ll, ll>
#define B 26

int cnt[B];

ll Solve() {
  string s;

  if (!getline(cin, s)) {
    exit(0);
  }

  for (int k = 0; k < B; ++k) {
    cnt[k] = 0;
  }

  for (char c : s) {
    if (!isalpha(c)) {
      continue;
    }
    ++cnt[tolower(c) - 'a'];
  }

  int odd_cnt = 0;
  for (int k = 0; k < B && odd_cnt < 2; ++k) {
    odd_cnt += cnt[k] % 2;
  }

  if (odd_cnt > 1) {
    return 0;
  }

  ll ans = 1;
  for (int k = 0, n = 0; k < B; ++k) {
    if (cnt[k] < 2) {
      continue;
    }

    int m = cnt[k] / 2;
    for (int i = 1; i <= m; ++i, ++n) {
      ll p = n + 1, q = i;

      ll g1 = __gcd(ans, q);
      ans /= g1, q /= g1;

      ll g2 = __gcd(p, q);
      p /= g2, q /= g2;

      ans *= p;
    }
  }

  return ans;
}

int main() {
  while (true) {
    printf("%lld\n", Solve());
  }
  return 0;
}