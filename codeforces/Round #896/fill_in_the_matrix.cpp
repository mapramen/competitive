#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int, int>
#define pll pair<ll, ll>

set<int> S;

int MEX(vector<int>& a) {
  S.clear();
  for (int x : a) {
    S.insert(x);
  }

  int ans = 0;
  while (S.count(ans)) {
    ++ans;
  }

  return ans;
}

void Solve() {
  int n, m;
  scanf("%d%d", &n, &m);

  vector<vector<int>> a(n, vector<int>(m));

  for (int i = 0; i < n; ++i) {
    int x = i < m - 1 ? i + 1 : m - 1;
    for (int j = 0; j < m; ++j, x = (x + 1) % m) {
      a[i][j] = x;
    }
  }

  vector<int> v;
  for (int j = 0; j < m; ++j) {
    vector<int> b;
    for (int i = 0; i < n; ++i) {
      b.push_back(a[i][j]);
    }
    v.push_back(MEX(b));
  }

  printf("%d\n", MEX(v));
  for (int i = 0; i < n; ++i) {
    for (int x : a[i]) {
      printf("%d ", x);
    }
    printf("\n");
  }
}

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    Solve();
  }
  return 0;
}