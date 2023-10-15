#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int, int>
#define pll pair<ll, ll>

double Solve() {
  int p0, p1, t, p;
  scanf("%d%d%d%d", &p0, &p1, &t, &p);
  return t * log(1.0 * p / p0) / log(1.0 * p1 / p0);
}

int main() {
  int t;
  scanf("%d", &t);
  for (int k = 1; k <= t; ++k) {
    printf("Scenario #%d: %.2lf\n", k, Solve());
  }
  return 0;
}