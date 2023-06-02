#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

typedef ll ftype;
typedef complex<ftype> point;
#define x real
#define y imag
#define N 1000001

ftype dot(point a, point b) {
  return (conj(a) * b).x();
}

ftype F(point a, ftype x) {
  return dot(a, {x, 1});
}

point line[4 * N];

void add_line(point nw, int v = 1, int l = 0, int r = N) {
  int m = (l + r) / 2;
  bool lef = F(nw, l) < F(line[v], l);
  bool mid = F(nw, m) < F(line[v], m);
  if (mid) {
    swap(line[v], nw);
  }
  if (r - l == 1) {
    return;
  } else if (lef != mid) {
    add_line(nw, 2 * v, l, m);
  } else {
    add_line(nw, 2 * v + 1, m, r);
  }
}

ftype get(int x, int v = 1, int l = 0, int r = N) {
  int m = (l + r) / 2;
  if (r - l == 1) {
    return F(line[v], x);
  } else if (x < m) {
    return min(F(line[v], x), get(x, 2 * v, l, m));
  } else {
    return min(F(line[v], x), get(x, 2 * v + 1, m, r));
  }
}

int s[N], f[N];

int main() {
  int n, m;
  scanf("%d%d", &n, &m);

  for (int i = 1; i <= n; ++i) {
    scanf("%d", &s[i]);
  }

  for (int i = 1; i <= n; ++i) {
    scanf("%d", &f[i]);
  }

  for (int v = 0; v < 4 * N; ++v) {
    line[v] = {N, 0};
  }

  add_line({m, 0});
  for (int i = 1; i < n; ++i) {
    add_line({f[i], get(s[i])});
  }

  printf("%lld\n", get(s[n]));

  return 0;
}