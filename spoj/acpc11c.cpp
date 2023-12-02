#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int, int>
#define pll pair<ll, ll>

ll Solve() {
  int n;
  scanf("%d", &n);

  vector<int> a(n);
  for (int& x : a) {
    scanf("%d", &x);
  }

  vector<ll> s(n);
  for (int i = 1; i < n; ++i) {
    s[i] = s[i - 1] + a[i - 1];
  }

  ll S = s.back() + a.back();

  ll ans = S;
  for (int i = 0; i < n; ++i) {
    int j = (i + 1) % n;
    ll ansx = S - a[i] + min(min(s[i], S - s[i]), min(s[j], S - s[j]));
    ans = min(ans, ansx);
  }
  return ans;
}

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    printf("%lld\n", Solve());
  }
  return 0;
}