#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int, int>
#define pll pair<ll, ll>

vector<int> Solve() {
  int n;
  scanf("%d", &n);

  int x = 1;
  vector<int> p(n);

  p[n / 2] = 1;
  x = 2;

  if (n > 1) {
    p[0] = 2;
    x = 3;
  }

  if (n > 2) {
    p[n - 1] = 3;
    x = 4;
  }

  for (int& i : p) {
    if (i == 0) {
      i = x++;
    }
  }

  return p;
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