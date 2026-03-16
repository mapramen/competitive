#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int, int>
#define pll pair<ll, ll>
#define N 200001

pii a[N];
int c[N];

int main() {
  int p, q, n;
  scanf("%d%d%d", &p, &q, &n);

  for (int i = 1; i <= n; ++i) {
    scanf("%d%d", &a[i].first, &a[i].second);
  }

  priority_queue<pii> P, Q, S;

  for (int i = 1; i <= n; ++i) {
    P.push({a[i].first, i});
    Q.push({a[i].second, i});
  }

  ll ans = 0;
  while (p--) {
    int i = P.top().second;
    P.pop();

    ans += a[i].first;
    S.push({a[i].second - a[i].first, i});
    c[i] = 1;
  }

  while (q--) {
    while (!P.empty() && c[P.top().second]) {
      P.pop();
    }

    while (!Q.empty() && c[Q.top().second]) {
      Q.pop();
    }

    if (!S.empty() && P.top().first + S.top().first > Q.top().first) {
      int i = P.top().second, j = S.top().second;
      P.pop(), S.pop();

      ans += a[i].first + a[j].second - a[j].first;
      S.push({a[i].second - a[i].first, i});
      c[i] = 1, c[j] = 2;
    } else {
      int j = Q.top().second;
      Q.pop();

      ans += a[j].second;
      c[j] = 2;
    }
  }

  printf("%lld\n", ans);

  return 0;
}