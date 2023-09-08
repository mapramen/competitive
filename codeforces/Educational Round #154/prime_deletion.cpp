#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int, int>
#define pll pair<ll, ll>

int Solve() {
  int n;
  scanf("%d", &n);

  bool one_present = false, three_present = false;
  for (; n > 0; n /= 10) {
    int d = n % 10;

    if (d == 1) {
      if (three_present) {
        return 13;
      }
      one_present = true;
    }

    if (d == 3) {
      if (one_present) {
        return 31;
      }
      three_present = true;
    }
  }

  return -1;
}

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    printf("%d\n", Solve());
  }
  return 0;
}