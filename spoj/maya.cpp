#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int, int>
#define pll pair<ll, ll>

vector<int> place_values = {1, 20, 360, 7200, 144000, 2880000, 57600000};

int ReadMayanDigit() {
  int dots = 0, dashes = 0;
  while (true) {
    char c = getchar();
    dots += (c == '.');
    dashes += (c == '-');
    if (c == '\n') {
      break;
    }
  }
  return dots + 5 * dashes;
}

int Solve() {
  int n;
  scanf("%d", &n);

  if (n == 0) {
    exit(0);
  }

  getchar();

  int ans = 0;
  while (n--) {
    ans += ReadMayanDigit() * place_values[n];
  }

  getchar();
  return ans;
}

int main() {
  while (true) {
    printf("%d\n", Solve());
  }
  return 0;
}