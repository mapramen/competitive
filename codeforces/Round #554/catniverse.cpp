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
#define N 180
#define MOD 1000000007

int A[N][N], B[N][N], temp[N][N];
vector<int> v;

int GetMappedValue(int k, int mask, int totalMasks){
  int x = k * totalMasks + mask;
  return lower_bound(v.begin(), v.end(), x) - v.begin();
}

void Initialise(int k, int m){
  int totalMasks = (1 << m);
  for(int mask = 0; mask < totalMasks; ++mask){
    for(int i = __builtin_popcount(mask); i <= k; ++i){
      v.push_back(i * totalMasks + mask);
    }
  }
  sort(v.begin(), v.end());

  for(int mask = 0; mask < totalMasks; ++mask){
    int nmask = 2 * (mask & ((1 << (m - 1)) - 1));
    int c = __builtin_popcount(mask);

    for(int i = c; i <= k; ++i){
      int y = GetMappedValue(i, mask, totalMasks), x = GetMappedValue(i, nmask, totalMasks);
      ++A[x][y];
    }

    for(int i = ++c; i <= k; ++i){
      int y = GetMappedValue(i - 1, mask, totalMasks), x = GetMappedValue(i, nmask + 1, totalMasks);
      A[x][y] += c;
    }
  }
}

void MatrixMultiplication(int n, int A[N][N], int B[N][N], int C[N][N]){
  for(int i = 0; i < n; ++i){
    for(int j = 0; j < n; ++j){
      int &val = temp[i][j];
      val = 0;
      for(int k = 0; k < n; ++k){
        if(A[i][k] && B[k][j]){
          val = (val + 1ll * A[i][k] * B[k][j]) % MOD;
        }
      }
    }
  }

  for(int i = 0; i < n; ++i){
    for(int j = 0; j < n; ++j){
      C[i][j] = temp[i][j];
    }
  }
}

void MatrixExponentation(int n, int m, int A[N][N], int B[N][N]){
  for( ; m; m /= 2){
    if(m % 2){
      MatrixMultiplication(n, A, B, B);
    }
    MatrixMultiplication(n, A, A, A);
  }
}

int main(){
  int n, k, m;
  cin >> n >> k >> m;

  Initialise(k, m);

  B[0][0] = 1;
  MatrixExponentation(v.size(), n, A, B);

  ll ans = 0;
  for(int mask = 0, totalMasks = (1 << m); mask < totalMasks; ++mask){
    if(__builtin_popcount(mask) <= k){
      ans = (ans + B[GetMappedValue(k, mask, totalMasks)][0]) % MOD;
    }
  }

  cout << ans << '\n';

  return 0;
}