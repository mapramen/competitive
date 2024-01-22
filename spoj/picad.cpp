#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int, int>
#define pll pair<ll, ll>

pii Solve() {
  int a, b;
  scanf("%d%d", &a, &b);
  a *= 2, b *= 2;

  int n;
  scanf("%d", &n);

  vector<pii> v;
  for (int i = 0; i < n; ++i) {
    int x, y;
    scanf("%d%d", &x, &y);
    x *= 2, y *= 2;

    v.push_back({x, 1});
    v.push_back({y + 1, -1});
  }
  v.push_back({a, 2});
  v.push_back({b, 2});

  sort(v.begin(), v.end());
  reverse(v.begin(), v.end());

  int min_ans = INT_MAX, max_ans = INT_MIN, cnt = 0;

  while (!v.empty()) {
    int i = v.back().first;
    while (!v.empty() && v.back().first == i) {
      int x = v.back().second;
      v.pop_back();

      if (x != 2) {
        cnt += x;
      }
    }

    if (a <= i && i <= b) {
      min_ans = min(min_ans, cnt);
      max_ans = max(max_ans, cnt);
    }
  }

  return {min_ans, max_ans};
}

int main() {
  int t = 10;
  while (t--) {
    auto [min_ans, max_ans] = Solve();
    printf("%d %d\n", min_ans, max_ans);
  }
  return 0;
}