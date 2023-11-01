#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int, int>
#define pll pair<ll, ll>

const double PI = 4 * atan(1);

double Solve() {
  int w, h;
  scanf("%d%d", &w, &h);

  if (w == 0 && h == 0) {
    exit(0);
  }

  // circumference along the longer side
  double r1 = min(w / 2.0, h / (2 * (PI + 1)));
  double h1 = w;

  // circumference along the shorter side
  double r2 = w / (2 * PI);
  double h2 = h - 2 * r2;

  return max(PI * r1 * r1 * h1, PI * r2 * r2 * h2);
}

int main() {
  while (true) {
    printf("%.3lf\n", Solve());
  }
  return 0;
}