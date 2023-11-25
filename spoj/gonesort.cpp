#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int, int>
#define pll pair<ll, ll>

vector<int> CoordinateCompress(vector<int> v) {
  vector<int> u(v);
  sort(u.begin(), u.end());
  u.erase(unique(u.begin(), u.end()), u.end());
  for (int& x : v) {
    x = lower_bound(u.begin(), u.end(), x) - u.begin() + 1;
  }
  return v;
}

int Solve() {
  int n;
  scanf("%d", &n);

  vector<int> a(n);
  for (int& x : a) {
    scanf("%d", &x);
  }
  a = CoordinateCompress(a);

  int ans = 0;

  vector<int> dp(n + 1);
  for (int x : a) {
    dp[x] = dp[x - 1] + 1;
    ans = max(ans, dp[x]);
  }

  return n - ans;
}

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    printf("%d\n", Solve());
  }
  return 0;
}