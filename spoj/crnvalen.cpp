#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int, int>
#define pll pair<ll, ll>

int Solve() {
  int n;
  scanf("%d", &n);

  vector<int> a(n);
  for (int& x : a) {
    scanf("%d", &x);
  }

  ll sum = 0;
  for (int& x : a) {
    sum += x;
  }

  if (sum % (n - 1) != 0) {
    return -1;
  }

  ll ans = sum / (n - 1);
  if (ans < 0 || ans > n) {
    return -1;
  }

  sum = 0;
  for (int& x : a) {
    if (x < 0 || x >= n || x > ans) {
      return -1;
    }

    x = ans - x;

    if (x > 1) {
      return -1;
    }

    sum += x;
  }

  return sum == ans ? ans : -1;
}

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    printf("%d\n", Solve());
  }
  return 0;
}