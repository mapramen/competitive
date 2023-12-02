#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int, int>
#define pll pair<ll, ll>
#define g 9.8

double Solve() {
  int u, h;
  scanf("%d%d", &u, &h);

  if (u == -1 && h == -1) {
    exit(0);
  }

  return (u / g) * sqrt(u * u + 2 * g * h);
}

int main() {
  while (true) {
    printf("%.6f\n", Solve());
  }
  return 0;
}