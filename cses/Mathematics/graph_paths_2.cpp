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

ll A[N][N], B[N][N], temp[N][N];
ll inf = 2E18;

void MatrixMulplication(ll A[N][N], ll B[N][N], ll C[N][N]){
  for(int i = 0; i < N; ++i){
    for(int j = 0; j < N; ++j){
      ll ans = inf;
      for(int k = 0; k < N; ++k){
        ans = min(ans, A[i][k] + B[k][j]);
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

void MatrixExponentiation(ll n, ll A[N][N], ll B[N][N]){
  for( ; n > 0; n /= 2){
    if(n % 2 == 1){
      MatrixMulplication(A, B, B);
    }
    MatrixMulplication(A, A, A);
  }
}

void Initialise(){
  for(int i = 0; i < N; ++i){
    for(int j = 0; j < N; ++j){
      A[i][j] = inf;
      B[i][j] = inf;
    }
    B[i][i] = 0;
  }
}

int main(){
  int n, m, k;

  cin >> n >> m >> k;

  Initialise();

  while(m--){
    int i, j, w;
    cin >> i >> j >> w;
    A[i - 1][j - 1] = min(A[i - 1][j - 1], 1ll * w);
  }

  MatrixExponentiation(k, A, B);

  ll ans = B[0][n - 1] >= inf ? -1 : B[0][n - 1];

  cout << ans << '\n';

  return 0;
}