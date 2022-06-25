#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 10
#define MOD 1000000007

int A[N][N], B[N][N], T[N][N];

void MatrixMultiplication(int A[N][N], int B[N][N], int C[N][N]){
  for(int i = 0; i < N; ++i){
    for(int j = 0; j < N; ++j){
      int ans = 0;
      for(int k = 0; k < N; ++k){
        ans = (ans + 1ll * A[i][k] * B[k][j]) % MOD;
      }
      T[i][j] = ans;
    }
  }

  for(int i = 0; i < N; ++i){
    for(int j = 0; j < N; ++j){
      C[i][j] = T[i][j];
    }
  }
}

int Calculate(int n){
  for(int i = 0; i < N; ++i){
    for(int j = 0; j < N; ++j){
      A[i][j] = 0, B[i][j] = 0;
    }
    B[i][i] = 1;
  }

  A[0][7] = 1;
  A[1][2] = A[1][4] = 1;
  A[2][1] = A[2][3] = A[2][5] = 1;
  A[3][2] = A[3][6] = 1;
  A[4][1] = A[4][5] = A[4][7] = 1;
  A[5][2] = A[5][4] = A[5][6] = A[5][8] = 1;
  A[6][3] = A[6][5] = A[6][9] = 1;
  A[7][4] = A[7][8] = A[7][0] = 1;
  A[8][5] = A[8][7] = A[8][9] = 1;
  A[9][6] = A[9][8] = 1;

  for(--n; n != 0; n /= 2){
    if(n % 2 == 1){
      MatrixMultiplication(B, A, B);
    }
    MatrixMultiplication(A, A, A);
  }

  int ans = 0;
  for(int i = 0; i < N; ++i){
    for(int j = 0; j < N; ++j){
      ans = (ans + B[i][j]) % MOD;
    }
  }

  return ans;
}

int Solve(){
  int n;
  scanf("%d", &n);
  return Calculate(n);
}

int main(){
  int t;
  scanf("%d", &t);
  while(t--){
    printf("%d\n", Solve());
  }
  return 0;
}