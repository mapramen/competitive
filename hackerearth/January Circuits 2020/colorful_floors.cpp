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
#define N 57
#define L 5
#define B 4
#define M 1024
#define MOD 1000000007

int h[M], d[N], c[M];
ll a[N][N], b[N][N], temp[N][N];

void ResetD(){
  for(int i = 0; i < B; ++i){
    d[i] = 0;
  }
}

void FillD(int mask){
  for(int i = 0; i < L; ++i){
    ++d[(mask % B)];
    mask /= B;
  }
}

bool IsValid(int k){
  for(int i = 0; i < B; ++i){
    if(d[i] > k){
      return false;
    }
  }
  return true;
}

bool IsValid(int k, int mask){
  ResetD();
  FillD(mask);
  return IsValid(k);
}

bool IsValid(int k, int mask1, int mask2){
  ResetD();
  FillD(mask1);
  FillD(mask2);
  return IsValid(k);
}

int GetMinMask(int mask){
  vector<int> v;
  for(int i = 0; i < N; ++i){
    v.push_back(mask % B);
    mask /= B;
  }
  sort(v.begin(), v.end());
  
  for(int x : v){
    mask = B * mask + x;
  }

  return mask;
}

void PreProcess(int k){
  vector<int> v;

  for(int i = 0; i < M; ++i){
    int x = GetMinMask(i);
    ++c[x];

    if(x == i){
      v.push_back(i);
      h[i] = v.size();
    }
  }

  for(int mask1 : v){
    if(IsValid(k, mask1)){
      a[0][h[mask1]] = c[mask1];
    }
    else{
      continue;
    }

    for(int mask2 : v){
      if(IsValid(k, mask1, mask2)){
        a[h[mask1]][h[mask2]] = c[mask2];
      }
    }
  }

  for(int i = 0; i < N; ++i){
    b[i][i] = 1;
  }
}

void MatrixMultiplication(ll a[N][N], ll b[N][N], ll c[N][N]){
  for(int i = 0; i < N; ++i){
    for(int j = 0; j < N; ++j){
      temp[i][j] = 0;
    }
  }

  for(int i = 0; i < N; ++i){
    for(int j = 0; j < N; ++j){
      int ans = 0;
      for(int k = 0; k < N; ++k){
        ans = (ans + a[i][k] * b[k][j]) % MOD;
      }
      temp[i][j] = ans;
    }
  }

  for(int i = 0; i < N; ++i){
    for(int j = 0; j < N; ++j){
      c[i][j] = temp[i][j];
    }
  }
}

void MatrixExponentation(ll a[N][N], ll n, ll b[N][N]){
  for( ; n > 0; n /= 2){
    if(n % 2){
      MatrixMultiplication(b, a, b);
    }
    MatrixMultiplication(a, a, a);
  }
}

int main(){
  int n, k;
  cin >> n >> k;

  PreProcess(k);
  MatrixExponentation(a, n, b);

  int ans = 0;
  for(int j = 1; j < N; ++j){
    ans = (ans + b[0][j]) % MOD;
  }

  cout << ans << '\n';

  return 0;
}