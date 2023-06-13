#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int, int>
#define pll pair<ll, ll>
#define M (1 << 19)

int val[M], lazy_update[M], min1[M], min2[M];

void UpdateNode(int k, int x) {
  val[k] += x, lazy_update[k] += x;
  min1[k] += x, min2[k] -= x;
}

void LazyUpdateChildren(int k) {
  UpdateNode(2 * k + 1, lazy_update[k]);
  UpdateNode(2 * k + 2, lazy_update[k]);
  lazy_update[k] = 0;
}

void Combine(int k) {
  min1[k] = min(min1[2 * k + 1], min1[2 * k + 2]);
  min2[k] = min(min2[2 * k + 1], min2[2 * k + 2]);
}

void Update(int k, int l, int r, int ql, int qr, int x) {
  if (qr < l || r < ql) {
    return;
  }

  if (ql <= l && r <= qr) {
    UpdateNode(k, x);
    return;
  }

  LazyUpdateChildren(k);

  int m = (l + r) / 2;
  Update(2 * k + 1, l, m, ql, qr, x);
  Update(2 * k + 2, m + 1, r, ql, qr, x);

  Combine(k);
}

int main() {
  int n;
  scanf("%d", &n);

  for (int i = 1, min_weight = INT_MAX, min_weight_stack = 1; i <= n; ++i) {
    int c, s;
    scanf("%d%d", &c, &s);

    c = n - c + 1;
    tie(min_weight, min_weight_stack) = min(make_pair(min_weight, min_weight_stack), make_pair(c, s));

    Update(0, 1, n, c, n, s == 1 ? 1 : -1);

    printf("%c\n", (min_weight_stack == 1 ? min1[0] : min2[0]) >= 0 ? (min_weight_stack == 1 ? '>' : '<') : '?');
  }

  return 0;
}