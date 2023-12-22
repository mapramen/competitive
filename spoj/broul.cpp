#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int, int>
#define pll pair<ll, ll>

int Solve() {
  int starting_pot_value, bet, ending_pot_value;
  scanf("%d%d%d", &starting_pot_value, &bet, &ending_pot_value);

  if (starting_pot_value == 0 && bet == 0 && ending_pot_value == 0) {
    exit(0);
  }

  int n = abs(ending_pot_value - starting_pot_value);
  if (n % bet != 0) {
    return -1;
  }

  n /= bet;

  return (n + 2) / 3;
}

int main() {
  while (true) {
    int ans = Solve();
    if (ans == -1) {
      printf("No accounting tablet\n");
    } else {
      printf("%d\n", ans);
    }
  }
  return 0;
}