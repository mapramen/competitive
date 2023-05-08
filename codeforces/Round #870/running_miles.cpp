#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int, int>
#define pll pair<ll, ll>

int Solve() {
  int n;
  scanf("%d", &n);

  int ans1 = -1E9, ans2 = -1E9, ans3 = -1E9;
  for (int i = 1; i <= n; ++i) {
    int x;
    scanf("%d", &x);

    ans3 = max(ans3, x - i + ans2);
    ans2 = max(ans2, x + ans1);
    ans1 = max(ans1, x + i);
  }

  return ans3;
}

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    printf("%d\n", Solve());
  }
  return 0;
}