#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int, int>
#define pll pair<ll, ll>

double Solve() {
  int r;
  scanf("%d", &r);

  // volume of tricylinder
  return 8 * (2 - sqrt(2)) * r * r * r;
}

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    printf("%.4lf\n", Solve());
  }
  return 0;
}