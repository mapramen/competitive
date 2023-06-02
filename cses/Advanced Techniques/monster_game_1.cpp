#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

typedef ll ftype;
typedef complex<ftype> point;
#define x real
#define y imag
#define N 200001

ftype dot(point a, point b) {
  return (conj(a) * b).x();
}

ftype cross(point a, point b) {
  return (conj(a) * b).y();
}

vector<point> hull, vecs;

void add_line(ftype k, ftype b) {
  point nw = {k, b};
  while (!vecs.empty() && dot(vecs.back(), nw - hull.back()) >= 0) {
    hull.pop_back();
    vecs.pop_back();
  }
  if (!hull.empty()) {
    point temp(0, 1);
    vecs.push_back(temp * (nw - hull.back()));
  }
  hull.push_back(nw);
}

ll get(ftype x) {
  point query = {x, 1};
  auto it = lower_bound(vecs.begin(), vecs.end(), query, [](point a, point b) {
    return cross(a, b) > 0;
  });
  return dot(query, hull[it - vecs.begin()]);
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

  add_line(m, 0);
  for (int i = 1; i < n; ++i) {
    add_line(f[i], get(s[i]));
  }

  printf("%lld\n", get(s[n]));

  return 0;
}