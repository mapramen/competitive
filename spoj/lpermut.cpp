#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int, int>
#define pll pair<ll, ll>

int main() {
  int n;
  scanf("%d", &n);

  vector<int> a(n);
  for (int& x : a) {
    scanf("%d", &x);
  }

  set<int> missing;
  for (int i = 1; i <= n + 1; i++) {
    missing.insert(i);
  }

  vector<int> cnt(n + 1);

  int ans = 0;
  for (int i = 0, j = 0; i < n; ++i) {
    ++cnt[a[i]];
    missing.erase(a[i]);

    for (; cnt[a[i]] > 1; ++j) {
      if (--cnt[a[j]] == 0) {
        missing.insert(a[j]);
      }
    }

    ans = max(ans, *missing.begin() - 1);
  }

  printf("%d\n", ans);

  return 0;
}