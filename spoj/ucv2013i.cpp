#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int, int>
#define pll pair<ll, ll>

const double PI = 4 * atan(1);

double Solve() {
  int r, n;
  scanf("%d%d", &r, &n);

  if (r == 0 && n == 0) {
    exit(0);
  }

  return r / sin(PI / (2 * n));
}

int main() {
  while (true) {
    printf("%.2lf\n", Solve());
  }
  return 0;
}