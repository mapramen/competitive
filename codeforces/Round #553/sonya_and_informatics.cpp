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

#define pii pair< int, int >
#define pll pair< ll, ll >
#define N 101
#define MOD 1000000007

ll a[N], A[N][N], B[N][N], temp[N][N];

ll ModExp(ll a, ll n){
  ll y = 1;
  for( ; n; n /= 2){
    if(n % 2){
      y = (y * a) % MOD;
    }
    a = (a * a) % MOD;
  }
  return y;
}

ll ModInv(ll a){
  return ModExp(a, MOD - 2);
}

void MatrixMultiplication(ll n, ll A[N][N], ll B[N][N], ll C[N][N]){
  for(int i = 0; i <= n; ++i){
    for(int j = 0; j <= n; ++j){
      ll &val = temp[i][j];
      val = 0;
      for(int k = 0; k <= n; ++k){
        val = (val + A[i][k] * B[k][j]) % MOD;
      }
    }
  }

  for(int i = 0; i <= n; ++i){
    for(int j = 0; j <= n; ++j){
      C[i][j] = temp[i][j];
    }
  }
}

void MatrixExponentation(ll n, ll m, ll A[N][N], ll B[N][N]){
  for(int i = 0; i <= m; ++i){
    for(int j = 0; j <= m; ++j){
      B[i][j] = 0;
    }
    B[i][i] = 1;
  }

  for( ; n; n /= 2){
    if(n % 2){
      MatrixMultiplication(m, A, B, B);
    }
    MatrixMultiplication(m, A, A, A);
  }
}

bool IsInValidRange(ll n, ll m, ll i){
  return i <= m && i + n >= 2 * m;
}

void PreProcess(ll n, ll m){
  ll denominator = n * (n - 1) / 2;
  ll inverseDenominator = ModInv(denominator);

  for(ll i = 0; i <= m; ++i){
    ll x = denominator;

    if(IsInValidRange(n, m, i - 1)){
      A[i][i - 1] = ((n - 2 * m + i) * i) % MOD;
      x -= A[i][i - 1];
    }

    if(IsInValidRange(n, m, i + 1)){
      A[i][i + 1] = ((m - i) * (m - i)) % MOD;
      x -= A[i][i + 1];
    }

    A[i][i] = x;
  }

  for(int i = 0; i <= m; ++i){
    for(int j = 0; j <= m; ++j){
      A[i][j] = (A[i][j] * inverseDenominator) % MOD;
    }
  }
}

int main(){
  ll n, k;
  cin >> n >> k;
  for(int i = 1; i <= n; ++i){
    cin >> a[i];
  }

  ll m = 0;
  for(int i = 1; i <= n; ++i){
    m += a[i];
  }

  if(2 * m > n){
    m = n - m;
    for(int i = 1; i <= n; ++i){
      a[i] = 1 - a[i];
    }

    for(int i = 1, j = n; i < j; ++i, --j){
      swap(a[i], a[j]);
    }
  }

  PreProcess(n, m);
  MatrixExponentation(k, m, A, B);

  ll l = m;
  for(int i = 1; i <= n - m; ++i){
    l -= a[i];
  }

  cout << B[l][m] << '\n';

  return 0;
}