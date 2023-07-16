#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int, int>
#define pll pair<ll, ll>

string Solve() {
  int n;
  scanf("%d", &n);

  int m = 1;
  for (; n % m == 0; ++m)
    ;

  string ans(n, 'a');
  for (int i = 0; i < min(n, m); ++i) {
    ans[i] += i;
  }

  for (int i = min(n, m); i < n; ++i) {
    ans[i] = ans[i - m];
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