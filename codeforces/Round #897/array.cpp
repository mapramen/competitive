#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int, int>
#define pll pair<ll, ll>

int Query(int i) {
  printf("? %d\n", i);
  fflush(stdout);
  int x;
  scanf("%d", &x);
  return x;
}

void PrintAns(int x) {
  printf("! %d\n", x);
  fflush(stdout);
}

void Solve() {
  int n, k;
  scanf("%d%d", &n, &k);

  int ans = 0;
  for (int i = 1; i + k - 1 <= n; i += k) {
    ans ^= Query(i);
  }

  int r = n % k;
  if (r != 0) {
    int d = r / 2;
    ans ^= Query(n - (k + d) + 1);
    ans ^= Query(n - k + 1);
  }

  PrintAns(ans);
}

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    Solve();
  }
  return 0;
}