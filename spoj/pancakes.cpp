#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int, int>
#define pll pair<ll, ll>
#define N 51

int ingredient_quantities[N], ingredient_required_quantities[N];

void Read(int n, int a[]) {
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &a[i]);
  }
}

pii Solve() {
  int n, r;
  scanf("%d%d", &n, &r);

  if (n == 0 && r == 0) {
    exit(0);
  }

  Read(n, ingredient_quantities);

  int max_pancakes_cnt = INT_MIN, max_pancakes_cnt_recipe_number = 0;

  for (int recipe_number = 1; recipe_number <= r; ++recipe_number) {
    Read(n, ingredient_required_quantities);

    int pancakes_cnt = INT_MAX;
    for (int i = 1; i <= n; ++i) {
      if (ingredient_required_quantities[i] == 0) {
        continue;
      }
      pancakes_cnt = min(pancakes_cnt, 10 * ingredient_quantities[i] / ingredient_required_quantities[i]);
    }

    if (pancakes_cnt > max_pancakes_cnt) {
      max_pancakes_cnt = pancakes_cnt;
      max_pancakes_cnt_recipe_number = recipe_number;
    }
  }

  return {max_pancakes_cnt_recipe_number, max_pancakes_cnt};
}

int main() {
  while (true) {
    auto [max_pancakes_cnt_recipe_number, max_pancakes_cnt] = Solve();
    printf("%d %d\n", max_pancakes_cnt_recipe_number, max_pancakes_cnt);
  }
  return 0;
}