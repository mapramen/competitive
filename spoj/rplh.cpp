#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int, int>
#define pll pair<ll, ll>

const double g = 9.806, PI = 2 * acos(0);

double Solve() {
  int R, u;
  scanf("%d%d", &R, &u);

  double t = g * R / (u * u);

  if (t > 1) {
    return -1;
  }

  return (180 / PI) * (asin(t) / 2);
}

int main() {
  int t;
  scanf("%d", &t);
  for (int k = 1; k <= t; ++k) {
    printf("Scenario #%d: ", k);

    double ans = Solve();
    if (ans < 0) {
      printf("-1\n");
    } else {
      printf("%.2lf\n", ans);
    }
  }
  return 0;
}