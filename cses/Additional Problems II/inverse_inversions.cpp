#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int, int>
#define pll pair<ll, ll>
#define N 1000001

bool used[N];
int p[N];

int main() {
  int n;
  ll k;
  scanf("%d%lld", &n, &k);

  for (int x = n, i = 1; x > 0; --x) {
    if (k >= x - 1) {
      p[i++] = x, k -= (x - 1);
      used[x] = true;
    }
  }

  for (int x = 1, i = 1; x <= n; ++x) {
    if (used[x]) {
      continue;
    }

    while (p[i] != 0) {
      ++i;
    }

    p[i] = x;
  }

  for (int i = 1; i <= n; ++i) {
    printf("%d ", p[i]);
  }
  printf("\n");

  return 0;
}