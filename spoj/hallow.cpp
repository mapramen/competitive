#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int, int>
#define pll pair<ll, ll>

vector<int> Solve() {
  int c, n;
  scanf("%d%d", &c, &n);

  if (c == 0 && n == 0) {
    exit(0);
  }

  vector<vector<int>> idxs(c);
  idxs[0].push_back(0);

  for (int i = 1, s = 0; i <= n; ++i) {
    int x;
    scanf("%d", &x);
    s = (s + x) % c;
    idxs[s].push_back(i);
  }

  int k = 0;
  for (; k < c && idxs[k].size() < 2; ++k)
    ;

  if (k == c) {
    return {};
  }

  vector<int> ans;
  for (int i = idxs[k][0] + 1; i <= idxs[k][1]; ++i) {
    ans.push_back(i);
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