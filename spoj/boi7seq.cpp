#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int, int>
#define pll pair<ll, ll>

int main() {
  int n;
  scanf("%d", &n);

  int x;
  scanf("%d", &x);

  ll ans = 0;
  while (--n) {
    int y;
    scanf("%d", &y);
    ans += max(x, y);
    x = y;
  }

  printf("%lld\n", ans);

  return 0;
}