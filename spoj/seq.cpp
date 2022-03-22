#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 10
#define MOD 1000000000

int b[N];
int A[N][N], B[N][N], temp[N][N];

void Reset(int n){
  for(int i = 0; i < n; ++i){
    for(int j = 0; j < n; ++j){
      A[i][j] = 0, B[i][j] = 0;
    }
  }

  for(int i = 0; i < n; ++i){
    B[i][i] = 1;
  }

  for(int i = 1; i < n; ++i){
    A[i][i - 1] = 1;
  }
}

void MatrixMultiplication(int n, int A[N][N], int B[N][N], int C[N][N]){
  for(int i = 0; i < n; ++i){
    for(int j = 0; j < n; ++j){
      int ans = 0;
      for(int k = 0; k < n; ++k){
        ans = (ans + 1ll * A[i][k] * B[k][j]) % MOD;
      }
      temp[i][j] = ans;
    }
  }

  for(int i = 0; i < n; ++i){
    for(int j = 0; j < n; ++j){
      C[i][j] = temp[i][j];
    }
  }
}

int Solve(){
  int k;
  scanf("%d", &k);

  Reset(k);

  for(int i = 0; i < k; ++i){
    scanf("%d", &b[i]);
    b[i] %= MOD;
  }

  for(int i = 0; i < k; ++i){
    scanf("%d", &A[0][i]);
    A[0][i] %= MOD;
  }

  int n;
  scanf("%d", &n);

  if(n <= k){
    return b[n - 1];
  }

  for(int i = 0, j = k - 1; i < j; ++i, --j){
    swap(b[i], b[j]);
  }

  n -= k;

  for( ; n > 0; n /= 2){
    if(n % 2 == 1){
      MatrixMultiplication(k, A, B, B);
    }
    MatrixMultiplication(k, A, A, A);
  }

  int ans = 0;
  for(int j = 0; j < k; ++j){
    ans = (ans + 1ll * B[0][j] * b[j]) % MOD;
  }

  return ans;
}

int main(){
  int t;
  scanf("%d", &t);
  while(t--){
    printf("%d\n", Solve());
  }
  return 0;
}