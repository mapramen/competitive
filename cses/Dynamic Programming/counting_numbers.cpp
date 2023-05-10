#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int, int>
#define pll pair<ll, ll>
#define L 20
#define B 10

ll dp_less[L][B], dp_equal[L][B];

vector<int> Int2Vec(ll n) {
  vector<int> v;
  while (n) {
    v.push_back(n % 10);
    n /= 10;
  }
  reverse(v.begin(), v.end());
  return v;
}

ll CountingNumbers(ll n) {
  if (n < 0) {
    return 0;
  }

  vector<int> v = Int2Vec(n);
  int len = v.size();
  for (int i = 1; i <= len; ++i) {
    for (int d = 0; d < B; ++d) {
      dp_less[i][d] = 0, dp_equal[i][d] = 0;
    }
  }

  for (int i = 1; i <= len; ++i) {
    for (int d = 1; d < B; ++d) {
      if (i == 1) {
        if (d < v[i - 1]) {
          dp_less[i][d] = 1;
        } else if (d == v[i - 1]) {
          dp_equal[i][d] = 1;
        }
      } else {
        dp_less[i][d] = 1;
      }
    }

    for (int d = 0; d < B; ++d) {
      for (int j = 0; j < B; ++j) {
        if (j == d) {
          continue;
        }

        dp_less[i][d] += dp_less[i - 1][j];

        if (d < v[i - 1]) {
          dp_less[i][d] += dp_equal[i - 1][j];
        }

        if (d == v[i - 1]) {
          dp_equal[i][d] += dp_equal[i - 1][j];
        }
      }
    }
  }

  ll ans = 1;
  for (int d = 0; d < B; ++d) {
    ans += dp_less[len][d] + dp_equal[len][d];
  }

  return ans;
}

int main() {
  ll l, r;
  scanf("%lld%lld", &l, &r);

  ll ans = CountingNumbers(r) - CountingNumbers(l - 1);
  printf("%lld\n", ans);

  return 0;
}