#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int, int>
#define pll pair<ll, ll>
#define N 100001

int a[N], d[N];

bool Solve() {
  int n, k;
  scanf("%d%d", &n, &k);

  for (int i = 1; i <= n; ++i) {
    scanf("%d", &a[i]);
    d[i] = 0;
  }

  if (k == 1) {
    for (int i = 1; i <= n; ++i) {
      if (a[i] != i) {
        return false;
      }
    }
    return true;
  }

  for (int i = 1, z = 1; i <= n; ++i) {
    if (d[i] != 0) {
      continue;
    }

    int x = z, j = i;
    for (; d[j] == 0; j = a[j], ++z) {
      d[j] = z;
    }

    if (d[j] < x) {
      continue;
    }

    int len = z - d[j];
    if (len != k) {
      return false;
    }
  }

  return true;
}

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    printf("%s\n", Solve() ? "YES" : "NO");
  }
  return 0;
}