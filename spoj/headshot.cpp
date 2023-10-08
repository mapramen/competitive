#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int, int>
#define pll pair<ll, ll>

int main() {
  string s;
  cin >> s;

  int n = s.size();
  int cnt_0 = 0, cnt_01 = 0, cnt_1 = 0;
  for (int i = 0; i < n; ++i) {
    cnt_0 += (s[i] == '0');
    cnt_1 += (s[i] == '1');
    cnt_01 += (s[i] == '0' && s[(i + 1) % n] == '1');
  }

  int p = cnt_01 * n - cnt_0 * cnt_1;

  if (p < 0) {
    cout << "SHOOT\n";
  } else if (p > 0) {
    cout << "ROTATE\n";
  } else {
    cout << "EQUAL\n";
  }

  return 0;
}