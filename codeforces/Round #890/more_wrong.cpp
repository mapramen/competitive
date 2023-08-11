#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int, int>
#define pll pair<ll, ll>

int Query(int l, int r) {
  if (l == r) {
    return 0;
  }

  printf("? %d %d\n", l, r);
  fflush(stdout);

  int ans;
  scanf("%d", &ans);
  return ans;
}

int Solve() {
  int n;
  scanf("%d", &n);

  vector<int> v(n);
  iota(v.begin(), v.end(), 1);

  while (v.size() > 1) {
    vector<int> u;
    while (v.size() % 2 == 1) {
      u.push_back(v.back());
      v.pop_back();
    }

    while (!v.empty()) {
      int i = v.back();
      v.pop_back();

      int j = v.back();
      v.pop_back();

      if (i > j) {
        swap(i, j);
      }

      if (Query(i, j - 1) == Query(i, j)) {
        u.push_back(j);
      } else {
        u.push_back(i);
      }
    }

    v = u;
  }

  return v.front();
}

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    printf("! %d\n", Solve());
    fflush(stdout);
  }
  return 0;
}