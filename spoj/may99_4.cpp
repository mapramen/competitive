#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int, int>
#define pll pair<ll, ll>
#define N 101
#define MOD 10000007

int c[N][N];

void Initialize() {
  for (int i = 0; i < N; ++i) {
    c[i][0] = 1;
    for (int j = 1; j <= i; ++j) {
      c[i][j] = (c[i - 1][j - 1] + c[i - 1][j]) % MOD;
    }
  }
}

int nCr(int n, int r) {
  if (n < 0 || r < 0 || n < r) {
    return -1;
  }

  return c[n][r];
}

int main() {
  Initialize();

  int n, r;
  scanf("%d%d", &n, &r);

  printf("%d\n", nCr(n - 1, r - 1));

  return 0;
}