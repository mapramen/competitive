#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int, int>
#define pll pair<ll, ll>

int GetLength(int a, int b) {
  int ans = 0;
  while (a != 1 && b != 1) {
    ans += (a / b);
    tie(a, b) = make_pair(b, a % b);
  }
  ans += max(a, b) - 1;
  return ans;
}

string GetString(int a, int b) {
  string s;
  while (a != 1 || b != 1) {
    if (a > b) {
      s.push_back('0');
      a -= b;
    } else {
      s.push_back('1');
      b -= a;
    }
  }
  return s;
}

int main() {
  int n;
  scanf("%d", &n);

  pii ans = {n, n};
  for (int a = 0; a <= n + 2; ++a) {
    int b = n + 2 - a;
    if (__gcd(a, b) != 1) {
      continue;
    }
    int len = GetLength(a, b);
    ans = min(ans, {len, a});
  }

  printf("%s\n", GetString(ans.second, n + 2 - ans.second).c_str());

  return 0;
}