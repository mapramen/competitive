#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int, int>
#define pll pair<ll, ll>

int Solve() {
  int n, k;
  scanf("%d%d", &n, &k);
  int a = n - k, b = (k - 1) / 2;
  return (a & b) == 0;
}

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    printf("%d\n", Solve());
  }
  return 0;
}