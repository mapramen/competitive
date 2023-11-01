#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int, int>
#define pll pair<ll, ll>

ll Solve() {
  int n, x;
  scanf("%d%d", &x, &n);

  vector<int> a(n);
  for (int& x : a) {
    scanf("%d", &x);
  }
  sort(a.begin(), a.end());

  ll ans = 0;
  for (int i = 0, j = n - 1; i < j;) {
    int s = a[i] + a[j];
    if (s > x) {
      --j;
      continue;
    }

    if (s < x) {
      ++i;
      continue;
    }

    if (a[i] == a[j]) {
      int k = j - i + 1;
      ans += (1ll * k * (k - 1)) / 2;
      break;
    }

    int k = 1;
    while (a[i] == a[i + 1]) {
      ++i, ++k;
    }

    int l = 1;
    while (a[j] == a[j - 1]) {
      --j, ++l;
    }

    ans += 1ll * k * l;

    ++i, --j;
  }

  return ans;
}

int main() {
  int t;
  scanf("%d", &t);
  for (int k = 1; k <= t; ++k) {
    printf("%d. %lld\n", k, Solve());
  }
  return 0;
}