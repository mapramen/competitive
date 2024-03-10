#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int, int>
#define pll pair<ll, ll>

ll Solve() {
  int a, b;
  if (scanf("%d%d", &a, &b) == EOF) {
    exit(0);
  }

  if (a > b) {
    swap(a, b);
  }

  int n = b - a + 1;
  return 1ll * n * (a + b) / 2;
}

int main() {
  while (true) {
    printf("%lld\n", Solve());
  }
  return 0;
}