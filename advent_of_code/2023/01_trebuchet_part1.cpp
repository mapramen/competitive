#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int, int>
#define pll pair<ll, ll>

int main() {
  long long ans = 0;

  string s;
  while (getline(cin, s)) {
    int n = s.size();

    int i = 0;
    for (; i < n && !isdigit(s[i]); ++i)
      ;

    int j = n - 1;
    for (; j >= 0 && !isdigit(s[j]); --j)
      ;

    ans += 10 * (s[i] - '0') + (s[j] - '0');
  }

  cout << ans << endl;

  return 0;
}