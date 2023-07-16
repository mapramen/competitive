#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int, int>
#define pll pair<ll, ll>

ll Solve() {
  int n;
  scanf("%d", &n);

  ll even_index_sum = 0, odd_index_sum = 0;
  int even_index_max = INT_MIN, odd_index_max = INT_MIN;

  while (n--) {
    int x;
    scanf("%d", &x);

    if (n % 2 == 0) {
      if (x > 0) {
        even_index_sum += x;
      }
      even_index_max = max(even_index_max, x);
    } else {
      if (x > 0) {
        odd_index_sum += x;
      }
      odd_index_max = max(odd_index_max, x);
    }
  }

  if (even_index_sum == 0 && even_index_max < 0) {
    even_index_sum = even_index_max;
  }

  if (odd_index_sum == 0 && odd_index_max < 0) {
    odd_index_sum = odd_index_max;
  }

  return max(even_index_sum, odd_index_sum);
}

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    printf("%lld\n", Solve());
  }
  return 0;
}