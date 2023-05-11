#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int, int>
#define pll pair<ll, ll>
#define M (1 << 19)

struct NodeData {
  ll sum;
  ll pref;
};

NodeData T[M];

NodeData Combine(NodeData a, NodeData b) {
  NodeData res;
  res.sum = a.sum + b.sum;
  res.pref = max(a.pref, a.sum + b.pref);
  return res;
}

void Update(int k, int l, int r, int i, int x) {
  if (i < l || r < i)
    return;
  if (l == r) {
    T[k].sum = x;
    T[k].pref = max(0, x);
    return;
  }
  int m = (l + r) / 2;
  Update(2 * k + 1, l, m, i, x);
  Update(2 * k + 2, m + 1, r, i, x);
  T[k] = Combine(T[2 * k + 1], T[2 * k + 2]);
}

NodeData Query(int k, int l, int r, int a, int b) {
  if (b < l || r < a)
    return {0, 0};
  if (a <= l && r <= b)
    return T[k];
  int m = (l + r) / 2;
  return Combine(Query(2 * k + 1, l, m, a, b),
                 Query(2 * k + 2, m + 1, r, a, b));
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
    int t, a, b;
    scanf("%d%d%d", &t, &a, &b);
    if (t == 1) {
      Update(0, 1, n, a, b);
    } else {
      printf("%lld\n", Query(0, 1, n, a, b).pref);
    }
  }

  return 0;
}