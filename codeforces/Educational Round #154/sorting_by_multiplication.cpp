#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int, int>
#define pll pair<ll, ll>
#define N 200002

int a[N];

int Solve() {
  int n;
  scanf("%d", &n);

  for (int i = 1; i <= n; ++i) {
    scanf("%d", &a[i]);
  }
  a[0] = INT_MAX, a[n + 1] = INT_MAX;

  int ansx = 0;
  for (int i = 2; i <= n; ++i) {
    ansx += (a[i] <= a[i - 1]);
  }

  int ans = ansx;
  ++ansx;
  for (int i = 1; i <= n; ++i) {
    ansx += (a[i] >= a[i - 1]);
    ansx -= (a[i + 1] <= a[i]);
    ans = min(ans, ansx);
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