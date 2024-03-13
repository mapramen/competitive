#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int, int>
#define pll pair<ll, ll>

int Solve() {
  int l, r;
  scanf("%d%d", &l, &r);

  for (int k = 30; k > -1; --k) {
    if ((l & (1 << k)) != (r & (1 << k))) {
      return (1 << (k + 1)) - 1;
    }
  }

  return 0;
}

int main() {
  int t = 1;
  while (t--) {
    printf("%d\n", Solve());
  }
  return 0;
}