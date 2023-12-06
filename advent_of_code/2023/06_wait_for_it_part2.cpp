#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int, int>
#define pll pair<ll, ll>

ll ExtractNumber() {
  string s;
  getline(cin, s);
  reverse(s.begin(), s.end());

  string t;
  while (!s.empty()) {
    char c = s.back();
    s.pop_back();

    if (isdigit(c)) {
      t.push_back(c);
    }
  }

  return stoll(t);
}

int main() {
  int T = ExtractNumber();
  ll D = ExtractNumber();

  int ans = 0;
  for (ll t = 0; t <= T; ++t) {
    ll d = t * (T - t);
    ans += (D < d);
  }

  cout << ans << endl;

  return 0;
}