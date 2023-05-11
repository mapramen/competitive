#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int, int>
#define pll pair<ll, ll>
#define M (1 << 19)

int a[M];

int lesser_index_min[M], greater_index_min[M];

void Update(int k, int l, int r, int i, int x) {
  if (i < l || r < i) {
    return;
  }

  if (i == l && r == i) {
    a[i] = x;
    lesser_index_min[k] = x - i;
    greater_index_min[k] = x + i;
    return;
  }

  int m = (l + r) / 2;
  Update(2 * k + 1, l, m, i, x);
  Update(2 * k + 2, m + 1, r, i, x);

  lesser_index_min[k] =
      min(lesser_index_min[2 * k + 1], lesser_index_min[2 * k + 2]);
  greater_index_min[k] =
      min(greater_index_min[2 * k + 1], greater_index_min[2 * k + 2]);
}

int Query(int k, int l, int r, int i) {
  if (i <= l) {
    return greater_index_min[k] - i;
  }

  if (r <= i) {
    return i + lesser_index_min[k];
  }

  int m = (l + r) / 2;
  return min(Query(2 * k + 1, l, m, i), Query(2 * k + 2, m + 1, r, i));
}

int main() {
  int n, q;
  scanf("%d%d", &n, &q);

  for (int i = 1; i <= n; ++i) {
    int x;
    scanf("%d", &x);
    Update(0, 1, n, i, x);
  }

  while (q--) {
    int t;
    scanf("%d", &t);

    if (t == 1) {
      int i, x;
      scanf("%d%d", &i, &x);
      Update(0, 1, n, i, x);
    } else {
      int i;
      scanf("%d", &i);
      printf("%d\n", Query(0, 1, n, i));
    }
  }

  return 0;
}