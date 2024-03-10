#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int, int>
#define pll pair<ll, ll>

ll GetTriangularNumber(int n) {
  return 1ll * n * (n + 1) / 2;
}

ll GetDiagonalValueEnd(int n, int x, int y) {
  int diagonal_number = x + y - 1;

  if (diagonal_number <= n) {
    return GetTriangularNumber(diagonal_number);
  }

  return 1ll * n * n - GetTriangularNumber(2 * n - diagonal_number - 1);
}

ll GetCellValue(int n, int x, int y) {
  int diagonal_number = x + y - 1;
  int diagonal_length = min(diagonal_number, 2 * n - diagonal_number);

  ll value_end = GetDiagonalValueEnd(n, x, y);
  ll value_start = value_end - diagonal_length + 1;

  int x_start = max(1, diagonal_number + 1 - n);
  int x_end = min(n, diagonal_number);

  return diagonal_number % 2 == 1
             ? value_end - (x - x_start)
             : value_start + (x - x_start);
}

ll Solve() {
  int n, k;
  string s;

  cin >> n >> k >> s;

  ll ans = 1;
  for (int i = 0, x = 1, y = 1; i < k; ++i) {
    char c = s[i];

    if (c == 'U') {
      --x;
    } else if (c == 'D') {
      ++x;
    } else if (c == 'L') {
      --y;
    } else if (c == 'R') {
      ++y;
    }

    ll value = GetCellValue(n, x, y);
    ans += value;
  }

  return ans;
}

int main() {
  int t = 1;
  while (t--) {
    printf("%lld\n", Solve());
  }
  return 0;
}