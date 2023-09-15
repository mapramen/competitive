#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int, int>
#define pll pair<ll, ll>

int Query(int x) {
  printf("%d\n", x);
  fflush(stdout);

  int y;
  scanf("%d", &y);
  return y;
}

void Solve() {
  int n;
  scanf("%d", &n);

  set<int> S;
  for (int i = 0; i <= n; ++i) {
    S.insert(i);
  }

  while (n--) {
    int x;
    scanf("%d", &x);
    S.erase(x);
  }

  while (true) {
    int x = *S.begin();
    S.erase(x);

    int y = Query(x);
    if (y == -1) {
      break;
    }

    S.insert(y);
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