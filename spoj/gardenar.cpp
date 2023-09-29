#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int, int>
#define pll pair<ll, ll>

double AreaOfTriangle(int a, int b, int c) {
  double s = (a + b + c) / 2.0;
  return sqrt(s * (s - a) * (s - b) * (s - c));
}

double AreaOfEquilateralTriangle(double a) {
  return sqrt(3) / 4.0 * a * a;
}

double Solve() {
  int a, b, c;
  scanf("%d%d%d", &a, &b, &c);

  double s = sqrt((a * a + b * b + c * c) / 2.0 + 2 * sqrt(3) * AreaOfTriangle(a, b, c));
  return AreaOfEquilateralTriangle(s);
}

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    printf("%.2lf\n", Solve());
  }
  return 0;
}