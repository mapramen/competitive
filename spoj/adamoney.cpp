#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 5
#define MOD 1000000007

int X[N], A[N][N], B[N][N], temp[N][N];

void Reset(){
  for(int i = 0; i < N; ++i){
    for(int j = 0; j < N; ++j){
      A[i][j] = 0, B[i][j] = 0;
    }
  }

  for(int i = 0; i < N; ++i){
    B[i][i] = 1;
  }

  A[0][0] = 1, A[0][1] = 2, A[0][3] = 5, A[0][4] = 1;
  for(int i = 1; i < N; ++i){
    A[i][i - 1] = 1;
  }
}

void MatrixMultiplication(int A[N][N], int B[N][N], int C[N][N]){
  for(int i = 0; i < N; ++i){
    for(int j = 0; j < N; ++j){
      int ans = 0;
      for(int k = 0; k < N; ++k){
        ans = (ans + 1ll * A[i][k] * B[k][j]) % MOD;
      }
      temp[i][j] = ans;
    }
  }

  for(int i = 0; i < N; ++i){
    for(int j = 0; j < N; ++j){
      C[i][j] = temp[i][j];
    }
  }
}

int Solve(){
  for(int i = 0; i < N; ++i){
    scanf("%d", &X[i]);
  }
  
  ll n;
  scanf("%lld", &n);
  
  if(n < N){
    return X[n];
  }
  
  reverse(X, X + N);

  Reset();

  for(n -= (N - 1); n > 0; n /= 2){
    if(n % 2 == 1){
      MatrixMultiplication(A, B, B);
    }
    MatrixMultiplication(A, A, A);
  }

  int ans = 0;
  for(int j = 0; j < N; ++j){
    ans = (ans + 1ll * B[0][j] * X[j]) % MOD;
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