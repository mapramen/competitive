#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 16
#define MOD 1000000007

ll A[N][N], B[N][N], T[N][N];

void MatrixMultiplication(ll A[N][N], ll B[N][N], ll C[N][N]){
  for(int i = 0; i < N; i++){
    for(int j = 0; j < N; j++){
      T[i][j] = 0;
      for(int k = 0; k < N; k++)
        T[i][j] = (T[i][j] + A[i][k] * B[k][j]) % MOD;
    }
  }

  for(int i = 0; i < N; i++)
    for(int j = 0; j < N; j++)
      C[i][j] = T[i][j];
}

void MatrixExponentation(ll A[N][N], ll B[N][N], ll n){
  while(n){
    if(n % 2)
      MatrixMultiplication(A, B, B);
    MatrixMultiplication(A, A, A);
    n /= 2;
  }
}

void ResetA(ll n){
  for(int i = 0; i < N; i++)
    for(int j = 0; j < N; j++)
      A[i][j] = 0;

  for(int i = 0; i <= n; i++){
    for(int j = i - 1; j <= i + 1; j++){
      if(j < 0 || j > n)
        continue;
      A[i][j] = 1;
    }
  }
}

int main(){
  ll n, k;

  B[0][0] = 1;

  cin >> n >> k;
  while(n--){
    ll a, b, c;
    cin >> a >> b >> c;
    ResetA(c);
    b = min(b, k);
    MatrixExponentation(A, B, b - a);
  }

  cout << B[0][0] << '\n';

  return 0;
}
