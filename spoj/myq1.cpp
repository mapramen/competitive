#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int, int>
#define pll pair<ll, ll>

string Solve() {
  int n;
  scanf("%d", &n);
  --n;

  if (n == 0) {
    return "poor conductor";
  }

  --n;
  int block = n / 10, seat = n % 10;
  int row = 2 * block + 1 + (seat >= 5);
  int col = seat < 5 ? seat : 9 - seat;

  string ans = to_string(row) + " ";
  if (col == 0) {
    ans += "W L";
  } else if (col == 1) {
    ans += "A L";
  } else if (col == 2) {
    ans += "A R";
  } else if (col == 3) {
    ans += "M R";
  } else if (col == 4) {
    ans += "W R";
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