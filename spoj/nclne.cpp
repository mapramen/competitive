#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int, int>
#define pll pair<ll, ll>

bool Solve() {
  int n;
  scanf("%d", &n);

  vector<int> a(n);
  for (int& x : a) {
    scanf("%d", &x);
  }
  reverse(a.begin(), a.end());

  int y = 0;
  for (int x : a) {
    if (x < 0 || y % 2 != 0) {
      return false;
    }
    y = y / 2 + x;
  }

  return y == 1;
}

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    printf("%s\n", Solve() ? "Yes" : "No");
  }
  return 0;
}