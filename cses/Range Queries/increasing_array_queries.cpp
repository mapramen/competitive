#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int, int>
#define pll pair<ll, ll>
#define N 200001

vector<vector<pii>> queries(N);
int a[N];
ll T1[N], T2[N], ans[N];

void Update(ll T[], int i, ll x) {
  for (; i < N; i += (i & -i)) {
    T[i] += x;
  }
}

ll Query(ll T[], int i) {
  ll ans = 0;
  for (; i > 0; i -= (i & -i)) {
    ans += T[i];
  }
  return ans;
}

void Update(int l, int r, int x) {
  Update(T1, l, x);
  Update(T1, r + 1, -x);
  Update(T2, l, -1ll * x * (l - 1));
  Update(T2, r + 1, 1ll * x * r);
}

ll Query(int i) {
  return Query(T1, i) * i + Query(T2, i);
}

ll Query(int l, int r) {
  return Query(r) - Query(l - 1);
}

int main() {
  int n, q;
  scanf("%d%d", &n, &q);

  for (int i = 1; i <= n; ++i) {
    scanf("%d", &a[i]);
  }

  for (int k = 1; k <= q; ++k) {
    int l, r;
    scanf("%d%d", &l, &r);
    queries[l].push_back({r, k});
  }

  vector<pii> S;
  for (int l = n; l > 0; --l) {
    int x = l;
    while (!S.empty() && S.back().first <= a[l]) {
      auto [val, y] = S.back();
      S.pop_back();
      Update(x + 1, y, a[l] - val);
      x = y;
    }
    S.push_back({a[l], x});

    for (auto [r, k] : queries[l]) {
      ans[k] = Query(l, r);
    }
  }

  for (int k = 1; k <= q; ++k) {
    printf("%lld\n", ans[k]);
  }

  return 0;
}