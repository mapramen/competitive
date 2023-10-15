#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int, int>
#define pll pair<ll, ll>

bool IsDivisible(string& s, int n) {
  int rem = 0;
  for (int i = 0; i < s.size(); ++i) {
    rem = (10ll * rem + (s[i] - '0')) % n;
  }
  return rem == 0;
}

pair<bool, bool> Solve() {
  string s;
  cin >> s;
  return {IsDivisible(s, 252), IsDivisible(s, 525)};
}

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    auto [ans1, ans2] = Solve();
    printf("%s %s\n", ans1 ? "Yes" : "No", ans2 ? "Yes" : "No");
  }
  return 0;
}