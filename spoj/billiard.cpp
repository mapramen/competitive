#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int, int>
#define pll pair<ll, ll>
#define pdd pair<double, double>

pdd Solve() {
  double a, b, s, m, n;
  scanf("%lf%lf%lf%lf%lf", &a, &b, &s, &m, &n);
  if (a == 0 && b == 0 && s == 0 && m == 0 && n == 0) {
    exit(0);
  }

  double x = a * m;
  double y = b * n;
  double v = sqrt(x * x + y * y) / s;
  double angle = atan2(y, x) * 180 / acos(-1);

  return {angle, v};
}

int main() {
  while (true) {
    auto [angle, velocity] = Solve();
    printf("%.2lf %.2lf\n", angle, velocity);
  }
  return 0;
}