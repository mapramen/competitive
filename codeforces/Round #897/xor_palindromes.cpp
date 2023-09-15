#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int, int>
#define pll pair<ll, ll>

string Solve() {
  int n;
  string s;
  cin >> n >> s;

  int cnt = 0;
  for (int x = 0, y = n - 1; x < y; ++x, --y) {
    cnt += (s[x] != s[y]);
  }

  string ans(n + 1, '0');
  for (int i = cnt, k = (n - 2 * cnt) / 2; k >= 0; cnt += 2, --k) {
    ans[cnt] = '1';
  }

  if (n % 2 != 0) {
    for (int i = n; i > 0; --i) {
      if (ans[i - 1] == '1') {
        ans[i] = '1';
      }
    }
  }

  return ans;
}

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    printf("%s\n", Solve().c_str());
  }
  return 0;
}