#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int, int>
#define pll pair<ll, ll>

int main() {
  int n, m, d, l;
  scanf("%d%d%d%d", &n, &m, &d, &l);

  vector<int> a(n);
  for (int& x : a) {
    scanf("%d", &x);
  }
  sort(a.begin(), a.end());

  int ans = 0;
  for (int i = 0; i < n; l += d) {
    for (int j = 0; j < m; ++i, ++j, ++ans) {
      i = lower_bound(a.begin() + i, a.end(), l) - a.begin();
      if (i == n) {
        break;
      }
    }
  }

  printf("%d\n", ans);

  return 0;
}