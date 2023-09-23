#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int, int>
#define pll pair<ll, ll>

int Solve() {
  int n;
  scanf("%d", &n);
  int m = (n - 1) / 2;
  return (1ll * m * m) % n;
}

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    printf("%d\n", Solve());
  }
  return 0;
}