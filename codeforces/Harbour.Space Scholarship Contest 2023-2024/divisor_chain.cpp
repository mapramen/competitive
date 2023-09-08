#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int, int>
#define pll pair<ll, ll>

vector<int> Solve() {
  int n;
  scanf("%d", &n);

  vector<int> v;
  while (__builtin_popcount(n) != 1) {
    v.push_back(n);
    n -= (1 << __builtin_ctz(n));
  }

  while (n != 0) {
    v.push_back(n);
    n /= 2;
  }

  return v;
}

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    vector<int> ans = Solve();
    printf("%lu\n", ans.size());
    for (int x : ans) {
      printf("%d ", x);
    }
    printf("\n");
  }
  return 0;
}