#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int, int>
#define pll pair<ll, ll>
#define N 1001

int a[N];

bool Check(int n, int k, int m) {
  for (int i = 1; i <= n; ++i) {
    ll sum = 0;
    bool possible = false;

    for (int j = i, x = m; j <= n; ++j, --x) {
      if (x <= a[j]) {
        possible = true;
        break;
      }

      sum += (x - a[j]);
    }

    if (possible && sum <= k) {
      return true;
    }
  }
  return false;
}

int BinarySearch(int n, int k) {
  int x = 1, y = 2E8, ans = 1;
  while (x <= y) {
    int mid = x + (y - x) / 2;
    if (Check(n, k, mid)) {
      ans = mid;
      x = mid + 1;
    } else {
      y = mid - 1;
    }
  }
  return ans;
}

int Solve() {
  int n, k;
  scanf("%d%d", &n, &k);

  for (int i = 1; i <= n; ++i) {
    scanf("%d", &a[i]);
  }

  return BinarySearch(n, k);
}

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    printf("%d\n", Solve());
  }
  return 0;
}