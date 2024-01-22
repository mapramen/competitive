#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int, int>
#define pll pair<ll, ll>

double Solve() {
  double h, w, f;
  scanf("%lf%lf%lf", &h, &w, &f);

  if (h == 0 && w == 0 && f == 0) {
    exit(0);
  }

  double ans = w * w * (f * f - 1) / (16 * h);
  ans = round(ans * 1000) / 1000;
  return ans;
}

int main() {
  while (true) {
    printf("%.3lf\n", Solve());
  }
  return 0;
}