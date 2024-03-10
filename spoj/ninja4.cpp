#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int, int>
#define pll pair<ll, ll>

pii Solve() {
  int n;
  scanf("%d", &n);

  int x = -2 * (n / 4), y = -2 * (n / 4);

  int r = n % 4;
  if (r == 1) {
    x += n;
  } else if (r == 2) {
    x += (n - 1);
    y += n;
  } else if (r == 3) {
    x -= 2;
    y += (n - 1);
  }

  return {x, y};
}

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    auto [x, y] = Solve();
    printf("%d %d\n", x, y);
  }
  return 0;
}