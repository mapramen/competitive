#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int, int>
#define pll pair<ll, ll>
#define N 1000001

ll c[N];

int main() {
  int n;
  scanf("%d", &n);

  while (n--) {
    int i;
    scanf("%d", &i);
    ++c[i];
  }

  for (int i = 1; i < N; ++i) {
    for (int j = i; j < N; j += i) {
      if (i != j) {
        c[i] += c[j];
      }
    }
  }

  for (int i = N - 1; i > 0; --i) {
    c[i] = c[i] * (c[i] - 1) / 2;
    for (int j = 2 * i; j < N; j += i) {
      c[i] -= c[j];
    }
  }

  printf("%lld\n", c[1]);

  return 0;
}