#include <bits/stdc++.h>
int a[101];
int main() {
  int t, n, i, j, x, y;
  scanf("%d", &t);
  while (t--) {
    scanf("%d", &n);
    for (i = 0; i < n; ++i) {
      for (j = 0, a[i] = 0, y = 0; j <= i; ++j) {
        scanf("%d", &x);
        x += std::max(y, a[j]);
        y = a[j];
        a[j] = x;
      }
    }
    printf("%d\n", *std::max_element(a, a + n));
  }
  return 0;
}