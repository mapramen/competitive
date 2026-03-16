#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int, int>
#define pll pair<ll, ll>
#define N 200001
#define B 30

ll sum[N][B];
int a[N], t[B];

int T[(1 << 19)][B];

void BuildSegmentTree(int k, int l, int r) {
  if (l == r) {
    for (int i = 0; i < B; ++i) {
      T[k][i] = INT_MAX;
    }

    int x = a[l];
    int i = 31 - __builtin_clz(x);
    T[k][i] = min(T[k][i], x);
    return;
  }

  int mid = (l + r) / 2;
  BuildSegmentTree(2 * k + 1, l, mid);
  BuildSegmentTree(2 * k + 2, mid + 1, r);

  for (int k1 = 2 * k + 1, k2 = 2 * k + 2, i = 0; i < B; ++i) {
    T[k][i] = min(T[k1][i], T[k2][i]);
  }
}

void Query(int k, int l, int r, int ql, int qr) {
  if (qr < l || r < ql) {
    return;
  }

  if (ql <= l && r <= qr) {
    for (int i = 0; i < B; ++i) {
      t[i] = min(t[i], T[k][i]);
    }
    return;
  }

  int mid = (l + r) / 2;
  Query(2 * k + 1, l, mid, ql, qr);
  Query(2 * k + 2, mid + 1, r, ql, qr);
}

ll Query(int n, int l, int r) {
  for (int i = 0; i < B; ++i) {
    t[i] = INT_MAX;
  }

  Query(0, 1, n, l, r);

  ll s = 0;
  for (int k = 0; k < B; ++k) {
    if (s >= ((1ll << (k + 1)) - 1) || t[k] <= s + 1) {
      s += sum[r][k] - sum[l - 1][k];
      continue;
    }
    break;
  }
  return s + 1;
}

int main() {
  int n, q;
  scanf("%d%d", &n, &q);

  for (int i = 1; i <= n; ++i) {
    int x;
    scanf("%d", &x);
    sum[i][31 - __builtin_clz(x)] = x;
    a[i] = x;
  }

  for (int i = 1; i <= n; ++i) {
    for (int k = 0; k < B; ++k) {
      sum[i][k] += sum[i - 1][k];
    }
  }

  BuildSegmentTree(0, 1, n);

  while (q--) {
    int l, r;
    scanf("%d%d", &l, &r);
    printf("%lld\n", Query(n, l, r));
  }

  return 0;
}