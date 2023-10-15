#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int, int>
#define pll pair<ll, ll>

vector<vector<int>> Multiply(vector<vector<int>>& A, vector<vector<int>>& B, int mod) {
  vector<vector<int>> C(2, vector<int>(2));

  for (int i = 0; i < 2; ++i) {
    for (int j = 0; j < 2; ++j) {
      int ans = 0;
      for (int k = 0; k < 2; ++k) {
        ans = (ans + 1ll * A[i][k] * B[k][j]) % mod;
      }
      C[i][j] = ans;
    }
  }

  return C;
}

int Fib(int n, int mod) {
  vector<vector<int>> A{{1, 1}, {1, 0}};
  vector<vector<int>> B{{1, 0}, {0, 1}};

  for (; n > 0; n /= 2) {
    if (n % 2 == 1) {
      B = Multiply(B, A, mod);
    }
    A = Multiply(A, A, mod);
  }

  return (B[0][1] + B[1][1]) % mod;
}

int Solve() {
  int n, m;
  scanf("%d%d", &n, &m);
  return Fib(n, 1 << m);
}

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    printf("%d\n", Solve());
  }
  return 0;
}