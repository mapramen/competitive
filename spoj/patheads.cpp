#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int, int>
#define pll pair<ll, ll>
#define N 1000001

int a[N], c[N];

int main() {
  int n;
  scanf("%d", &n);

  for (int i = 1; i <= n; ++i) {
    scanf("%d", &a[i]);
    ++c[a[i]];
  }

  for (int i = N - 1; i > 0; --i) {
    for (int j = 2 * i; j < N; j += i) {
      c[j] += c[i];
    }
  }

  for (int i = 1; i <= n; ++i) {
    printf("%d\n", c[a[i]] - 1);
  }

  return 0;
}