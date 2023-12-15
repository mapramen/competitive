#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int, int>
#define pll pair<ll, ll>

int main() {
  string s;
  cin >> s;

  ll ans = 0;
  reverse(s.begin(), s.end());

  int hsh = 0;
  while (!s.empty()) {
    char c = s.back();
    s.pop_back();

    if (c != ',') {
      hsh += c;
      hsh *= 17;
      hsh %= 256;
    }

    if (c == ',' || s.empty()) {
      ans += hsh;
      hsh = 0;
      continue;
    }
  }

  cout << ans << endl;

  return 0;
}