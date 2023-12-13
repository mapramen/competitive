#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int, int>
#define pll pair<ll, ll>

char op[10];

int Solve() {
  int n;
  scanf("%d", &n);

  if (n == 0) {
    exit(0);
  }

  int ans = 65536;
  while (n--) {
    int x;
    scanf("%s%d", op, &x);
    if (op[0] == 'A') {
      continue;
    }
    ans /= __gcd(ans, x);
  }

  return ans;
}

int main() {
  while (true) {
    printf("%d\n", Solve());
  }
  return 0;
}