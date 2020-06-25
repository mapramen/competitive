#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <vector>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <deque>
#include <cmath>
#include <utility>
#include <algorithm>
#include <bitset>
#include <climits>
#include <random>
#include <chrono>
#include <cassert>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 100
#define MOD 1000000007

int A[N][N], B[N][N], temp[N][N];

void MatrixMulplication(int A[N][N], int B[N][N], int C[N][N]){
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

void MatrixExponentiation(ll n, int A[N][N], int B[N][N]){
  for( ; n > 0; n /= 2){
    if(n % 2 == 1){
      MatrixMulplication(A, B, B);
    }
    MatrixMulplication(A, A, A);
  }
}

int main(){
  int n, m, k;

  cin >> n >> m >> k;

  while(m--){
    int i, j;
    cin >> i >> j;
    ++A[i - 1][j - 1];
  }
  
  for(int i = 0; i < n; ++i){
    B[i][i] = 1;
  }

  MatrixExponentiation(k, A, B);

  cout << B[0][n - 1] << '\n';

  return 0;
}