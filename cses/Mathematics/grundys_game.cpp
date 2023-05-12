#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int, int>
#define pll pair<ll, ll>

vector<int> losing_positions = {0, 1, 2, 4, 7, 10, 20, 23, 26, 50, 53, 270, 273, 276, 282, 285, 288, 316, 334, 337, 340, 346, 359, 362, 365, 386, 389, 392, 566, 630, 633, 636, 639, 673, 676, 682, 685, 923, 926, 929, 932, 1222};

bool Solve() {
  int n;
  scanf("%d", &n);
  return find(losing_positions.begin(), losing_positions.end(), n) == losing_positions.end();
}

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    printf("%s\n", Solve() ? "first" : "second");
  }
  return 0;
}