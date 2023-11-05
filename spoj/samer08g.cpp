#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int, int>
#define pll pair<ll, ll>

vector<int> Solve() {
  int n;
  scanf("%d", &n);

  if (n == 0) {
    exit(0);
  }

  vector<int> ans(n);
  for (int x = 1; x <= n; ++x) {
    int c, p;
    scanf("%d%d", &c, &p);

    int y = x + p;
    if (y < 1 || y > n) {
      continue;
    }

    ans[y - 1] = c;
  }

  if (*min_element(ans.begin(), ans.end()) == 0) {
    return {-1};
  }

  return ans;
}

int main() {
  while (true) {
    for (int x : Solve()) {
      printf("%d ", x);
    }
    printf("\n");
  }
  return 0;
}