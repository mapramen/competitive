#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int, int>
#define pll pair<ll, ll>

int Solve(int n) {
  if (n < 0) {
    return n;
  }

  if (n == 1) {
    return -3;
  }

  if (n == 2) {
    return -2;
  }

  if (n == 5) {
    return -3;
  }

  return -4;
}

void Solve() {
  int n;
  scanf("%d", &n);

  while (n--) {
    int x;
    scanf("%d", &x);
    printf("%d ", Solve(x));
  }
  printf("\n");
}

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    Solve();
  }
  return 0;
}