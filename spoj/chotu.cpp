#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int, int>
#define pll pair<ll, ll>

double Solve() {
  int x, y;
  scanf("%d%d", &x, &y);
  return 2 * sqrt(x * x - y * y);
}

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    printf("%.3lf\n", Solve());
  }
  return 0;
}