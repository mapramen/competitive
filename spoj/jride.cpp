#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int, int>
#define pll pair<ll, ll>

tuple<int, int, int, int> Solve() {
  int n;
  scanf("%d", &n);

  tuple<int, int, int, int> ans = {0, 0, 0, 0};
  for (int i = 1, j = 2, s = 0; j <= n; ++j) {
    int x;
    scanf("%d", &x);

    if (s < 0) {
      s = 0, i = j - 1;
    }

    s += x;
    ans = max(ans, {s, j - i + 1, -i, j});
  }

  return ans;
}

int main() {
  int t;
  scanf("%d", &t);
  for (int k = 1; k <= t; ++k) {
    auto [ans, _, i, j] = Solve();
    if (ans <= 0) {
      printf("Route %d has no nice parts\n", k);
    } else {
      printf("The nicest part of route %d is between stops %d and %d\n", k, -i, j);
    }
  }
  return 0;
}