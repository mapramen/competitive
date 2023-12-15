#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int, int>
#define pll pair<ll, ll>

vector<int> Solve(int n, int m) {
  int s = n * (n - 1) / 2;
  if ((m + s) % 2 != 0 || m < -s || m > s) {
    return {};
  }

  if (m < 0) {
    vector<int> ans = Solve(n, -m);
    for (int& x : ans) {
      x = -x;
    }
    return ans;
  }

  m = s - m;

  vector<int> a(n);

  for (int i = n - 1; i > 0; --i) {
    if (2 * i > m) {
      continue;
    }
    a[n - i] -= 2;
    m -= 2 * i;
  }

  for (int i = 1; i < n; ++i) {
    a[i] += a[i - 1];
  }

  for (int i = 0; i < n; ++i) {
    a[i] += i;
  }

  return a;
}

vector<int> Solve() {
  int n, m;
  scanf("%d%d", &n, &m);
  return Solve(n, m);
}

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    vector<int> ans = Solve();
    if (ans.empty()) {
      printf("No\n");
    } else {
      for (int x : ans) {
        printf("%d\n", x);
      }
    }
    printf("\n");
  }
  return 0;
}