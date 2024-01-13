#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ull;

int main() {
  int m, n;
  scanf("%d%d", &m, &n);

  ull ans = 0;
  map<int, int> C;
  C[1] = 0;

  while (n--) {
    int x;
    scanf("%d", &x);
    ans += 1llu * x * x;
    ++C[x];
  }

  while (!C.empty() && m > 0 && C.rbegin()->first != 1 && C.rbegin()->second <= m) {
    auto [x, cx] = *C.rbegin();
    C.erase(x);

    auto y = C.rbegin()->first;

    int z = min(1ll * cx * (x - y), 1ll * m);
    z /= cx;

    y = x - z;
    m -= cx * z;

    ans -= 1llu * cx * (x - y) * (x + y);
    C[y] += cx;
  }

  while (!C.empty() && m > 0) {
    auto [x, cx] = *C.rbegin();
    C.erase(x);

    if (x == 0 || cx == 0) {
      continue;
    }

    ans -= (2 * x - 1);
    --cx;
    --m;

    C[x] = cx;

    if (x > 0) {
      ++C[x - 1];
    }
  }

  printf("%llu\n", ans);

  return 0;
}