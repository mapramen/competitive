#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 10
#define MOD 1000000007

int A[N][N], B[N][N], temp[N][N];

bool IsPrime(int n){
  if(n < 2){
    return false;
  }

  for(int i = 2; i * i <= n; ++i){
    if(n % i == 0){
      return false;
    }
  }

  return true;
}

void Reset(){
  for(int i = 0; i < N; ++i){
    for(int j = 0; j < N; ++j){
      A[i][j] = 0, B[i][j] = 0;
    }
  }

  for(int i = 0; i < N; ++i){
    B[i][i] = 1;
  }

  for(int i = 1; i < N; ++i){
    for(int j = 1; j < N; ++j){
      if(IsPrime(i + j)){
        A[i][j] = 1, ++A[0][i];
      }
    }
  }
  A[0][0] = 1;
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
  int n;
  scanf("%d", &n);

  Reset();

  for(--n; n > 0; n /= 2){
    if(n % 2 == 1){
      MatrixMultiplication(A, B, B);
    }
    MatrixMultiplication(A, A, A);
  }

  int ans = (4ll * B[0][0]) % MOD;
  for(int i = 1; i < N; ++i){
    ans = (ans + B[0][i]) % MOD;
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