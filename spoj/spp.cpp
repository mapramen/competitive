#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define K 16

int b[K], c[K], A[K][K], B[K][K], t[K][K];

void MatrixMultiplication(int n, int A[K][K], int B[K][K], int C[K][K], int mod){
  for(int i = 0; i < n; ++i){
    for(int j = 0; j < n; ++j){
      int ans = 0;
      for(int k = 0; k < n; ++k){
        ans = (ans + 1ll * A[i][k] * B[k][j]) % mod;
      }
      t[i][j] = ans;
    }
  }

  for(int i = 0; i < n; ++i){
    for(int j = 0; j < n; ++j){
      C[i][j] = t[i][j];
    }
  }
}

int Sum(int k, ll n, int mod){
  if(n <= k){
    int ans = 0;
    for(int i = 1; i <= n; ++i){
      ans = (ans + b[i]) % mod;
    }
    return (mod + ans) % mod;
  }

  for(int i = 0; i <= k; ++i){
    for(int j = 0; j <= k; ++j){
      A[i][j] = 0, B[i][j] = 0;
    }
    B[i][i] = 1;
  }

  A[0][0] = 1 + c[1], A[0][k] = -c[k];
  for(int i = 1; i < k; ++i){
    A[0][i] = c[i + 1] - c[i];
  }

  for(int i = 1; i <= k; ++i){
    A[i][i - 1] = 1;
  }

  for(n -= k; n > 0; n /= 2){
    if(n % 2 == 1){
      MatrixMultiplication(k + 1, A, B, B, mod);
    }
    MatrixMultiplication(k + 1, A, A, A, mod);
  }

  int ans = 0, s = 0;
  for(int i = 0; i <= k; ++i){
    s = (s + b[i]) % mod;
    ans = (ans + 1ll * B[0][k - i] * s) % mod;
  }

  return (mod + ans) % mod;
}

int Sum(int k, ll m, ll n, int mod){
  return (mod + Sum(k, n, mod) - Sum(k, m - 1, mod)) % mod;
}

int Solve(){
  int k;
  scanf("%d", &k);

  for(int i = 1; i <= k; ++i){
    scanf("%d", &b[i]);
  }

  for(int i = 1; i <= k; ++i){
    scanf("%d", &c[i]);
  }

  ll m, n, mod;
  scanf("%lld%lld%lld", &m, &n, &mod);

  return Sum(k, m, n, mod);
}

int main(){
  int t;
  scanf("%d", &t);
  while(t--){
    printf("%d\n", Solve());
  }
  return 0;
}