#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int, int>
#define pll pair<ll, ll>
#define N 17

char s[N];
int a[N], b[N];

int Calculate(int n, int m, int mask) {
  for (int i = 0; i < n; ++i) {
    a[i] = b[i];
  }

  int ans = 0;
  for (int i = 0; i < n; ++i) {
    ans += __builtin_popcount(mask);

    a[i + 1] ^= mask;

    mask = mask ^ (mask >> 1) ^ ((mask << 1) & ((1 << m) - 1));
    mask ^= a[i];
  }
  return mask == 0 ? ans : INT_MAX;
}

int Solve() {
  int n, m;
  scanf("%d%d", &n, &m);

  if (n == 0 && m == 0) {
    exit(0);
  }

  for (int i = 0; i < n; ++i) {
    scanf("%s", s);

    int on_mask = 0;
    for (int j = 0; j < m; ++j) {
      if (s[j] == 'X') {
        on_mask |= (1 << j);
      }
    }
    b[i] = on_mask;
  }

  int ans = INT_MAX;
  for (int mask = 0; mask < (1 << m); ++mask) {
    ans = min(ans, Calculate(n, m, mask));
  }
  return ans;
}

int main() {
  while (true) {
    int ans = Solve();
    if (ans != INT_MAX) {
      printf("You have to tap %d tiles.\n", ans);
    } else {
      printf("Damaged billboard.\n");
    }
  }
  return 0;
}