#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int, int>
#define pll pair<ll, ll>
#define N 100001

int a[N];

int ReadAndCollect(int n, int x) {
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &a[i]);
  }

  int ans = 0;
  for (int i = 1; i <= n && (x & a[i]) == a[i]; ++i) {
    ans |= a[i];
  }
  return ans;
}

bool Solve() {
  int n, x;
  scanf("%d%d", &n, &x);

  int ans = 0;
  for (int i = 0; i < 3; ++i) {
    ans |= ReadAndCollect(n, x);
  }

  return ans == x;
}

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    printf("%s\n", Solve() ? "YES" : "NO");
  }
  return 0;
}