#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int, int>
#define pll pair<ll, ll>

int main() {
  int n;
  scanf("%d", &n);

  --n;

  int ans = 0;
  for (int i = 0; i <= n; ++i) {
    int x;
    scanf("%d", &x);
    if ((n & i) == i) {
      ans ^= x;
    }
  }

  printf("%d\n", ans);

  return 0;
}