#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

typedef ll ftype;
typedef complex<ftype> point;
#define x real
#define y imag
#define N 3001

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
ll dp[N];

int main() {
  int n, m;
  scanf("%d%d", &n, &m);

  for (int i = 1; i <= n; ++i) {
    scanf("%d", &s[i]);
  }

  for (int i = 1; i <= n; ++i) {
    s[i] += s[i - 1];
    dp[i] = 1ll * s[i] * s[i];
  }

  for (int k = 2; k <= m; ++k) {
    vecs.clear(), hull.clear();

    add_line(-2 * s[k - 1], dp[k - 1] + 1ll * s[k - 1] * s[k - 1]);

    for (int i = k; i <= n; ++i) {
      ll ans = get(s[i]) + 1ll * s[i] * s[i];
      add_line(-2 * s[i], dp[i] + 1ll * s[i] * s[i]);
      dp[i] = ans;
    }
  }

  printf("%lld\n", dp[n]);

  return 0;
}
