#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int, int>
#define pll pair<ll, ll>

int Solve() {
  int n, m;
  scanf("%d%d", &n, &m);

  int x, y;
  scanf("%d%d", &x, &y);

  return max(x - 1, n - x) + max(y - 1, m - y);
}

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    printf("%d\n", Solve());
  }
  return 0;
}