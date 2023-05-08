#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int, int>
#define pll pair<ll, ll>
#define N 2
#define MOD 1000000007

int A[N][N], B[N][N], temp[N][N];

void MatrixMulplication(int A[N][N], int B[N][N], int C[N][N]) {
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < N; ++j) {
      int ans = 0;
      for (int k = 0; k < N; ++k) {
        ans = (ans + 1ll * A[i][k] * B[k][j]) % MOD;
      }
      temp[i][j] = ans;
    }
  }

  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < N; ++j) {
      C[i][j] = temp[i][j];
    }
  }
}

void MatrixExponentiation(ll n, int A[N][N], int B[N][N]) {
  for (; n > 0; n /= 2) {
    if (n % 2 == 1) {
      MatrixMulplication(A, B, B);
    }
    MatrixMulplication(A, A, A);
  }
}

int Solve() {
  int n;
  scanf("%d", &n);

  if (n == 0) {
    return 1;
  }

  if (n == 1) {
    return 2;
  }

  if (n == 2) {
    return 8;
  }

  A[0][0] = 6, A[0][1] = MOD - 7, A[1][0] = 1, A[1][1] = 0;
  B[0][0] = 1, B[0][1] = 0, B[1][0] = 0, B[1][1] = 1;
  MatrixExponentiation(n - 2, A, B);

  return (8ll * B[0][0] + 2ll * B[0][1]) % MOD;
}

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    printf("%d\n", Solve());
  }
  return 0;
}