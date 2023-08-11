#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int, int>
#define pll pair<ll, ll>
#define N 51

int a[N];

int Solve() {
  int n;
  scanf("%d", &n);

  for (int i = 1; i <= n; ++i) {
    scanf("%d", &a[i]);
  }

  int ans = 0;
  for (int i = 2; i <= n; ++i) {
    if (a[i - 1] > a[i]) {
      ans = max(ans, a[i - 1]);
    }
  }

  return ans;
}

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    printf("%d\n", Solve());
  }
  return 0;
}