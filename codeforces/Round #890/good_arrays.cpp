#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int, int>
#define pll pair<ll, ll>

bool Solve() {
  int n;
  scanf("%d", &n);

  int one_cnt = 0;
  ll non_one_sum = 0;
  for (int i = 0; i < n; ++i) {
    int x;
    scanf("%d", &x);
    if (x == 1) {
      ++one_cnt;
    } else {
      non_one_sum += x;
    }
  }

  if (n == 1) {
    return false;
  }

  if (one_cnt == 0) {
    return true;
  }

  return one_cnt <= non_one_sum - (n - one_cnt);
}

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    printf("%s\n", Solve() ? "YES" : "NO");
  }
  return 0;
}