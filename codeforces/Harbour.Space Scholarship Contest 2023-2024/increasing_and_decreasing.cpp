#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int, int>
#define pll pair<ll, ll>

vector<int> Solve() {
  int x, y, n;
  scanf("%d%d%d", &x, &y, &n);

  if (x + n * (n - 1) / 2 > y) {
    return vector<int>{-1};
  }

  vector<int> a(n);
  a[0] = x, a[n - 1] = y;
  for (int i = n - 2, d = 1; i > 0; --i, ++d) {
    a[i] = a[i + 1] - d;
  }

  return a;
}

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    for (int x : Solve()) {
      printf("%d ", x);
    }
    printf("\n");
  }
  return 0;
}