#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int, int>
#define pll pair<ll, ll>
#define N 5002

int chocolates[N], strawberries[N], bananas[N];
pii prefix_max_bananas[N], suffix_max_bananas[N];

tuple<int, int, int> Solve() {
  int n;
  scanf("%d", &n);

  for (int i = 1; i <= n; ++i) {
    scanf("%d", &chocolates[i]);
    scanf("%d", &strawberries[i]);
    scanf("%d", &bananas[i]);
  }

  prefix_max_bananas[0] = {0, 0};
  for (int i = 1; i <= n; ++i) {
    prefix_max_bananas[i] = max(prefix_max_bananas[i - 1], {bananas[i], i});
  }

  suffix_max_bananas[n + 1] = {0, n + 1};
  for (int i = n; i > 0; --i) {
    suffix_max_bananas[i] = max(suffix_max_bananas[i + 1], {bananas[i], i});
  }

  tuple<int, int, int, int> ans = {0, 1, 2, 3};
  for (int i = 1; i <= n; ++i) {
    pii in_between_max_bananas = {0, 0};
    for (int j = i + 1; j <= n; ++j) {
      pii max_bananas = in_between_max_bananas;
      max_bananas = max(max_bananas, prefix_max_bananas[i - 1]);
      max_bananas = max(max_bananas, suffix_max_bananas[j + 1]);

      tuple<int, int, int, int> current_ans1 = {chocolates[i] + strawberries[j] + max_bananas.first, i, j, max_bananas.second};
      tuple<int, int, int, int> current_ans2 = {chocolates[j] + strawberries[i] + max_bananas.first, j, i, max_bananas.second};
      ans = max(ans, max(current_ans1, current_ans2));

      in_between_max_bananas = max(in_between_max_bananas, {bananas[j], j});
    }
  }

  auto [_, chocolate_bag, strawberry_bag, banana_bag] = ans;

  return {chocolate_bag, strawberry_bag, banana_bag};
}

int main() {
  int t = 1;
  while (t--) {
    auto [chocolate_bag, strawberry_bag, banana_bag] = Solve();
    printf("%d\n", chocolate_bag - 1);
    printf("%d\n", strawberry_bag - 1);
    printf("%d\n", banana_bag - 1);
  }
  return 0;
}