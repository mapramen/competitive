#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int, int>
#define pll pair<ll, ll>

int Solve() {
  int n;
  scanf("%d", &n);

  set<int> win_pos, lose_pos;
  win_pos.insert(INT_MAX);
  lose_pos.insert(INT_MAX);

  for (int i = 1; i <= n; ++i) {
    int x;
    scanf("%d", &x);

    if ((x < *win_pos.begin() && x < *lose_pos.begin()) || *lose_pos.begin() < x) {
      win_pos.insert(x);
    } else {
      lose_pos.insert(x);
    }
  }

  return lose_pos.size() - 1;
}

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    printf("%d\n", Solve());
  }
  return 0;
}