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
#define K 8
#define N (K * K)

double A[N][N], B[N][N], temp[N][N];
vector<pii> moves{{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

void MatrixMulplication(double A[N][N], double B[N][N], double C[N][N]){
  for(int i = 0; i < N; ++i){
    for(int j = 0; j < N; ++j){
      double ans = 0;
      for(int k = 0; k < N; ++k){
        ans = ans + A[i][k] * B[k][j];
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

void MatrixExponentiation(ll n, double A[N][N], double B[N][N]){
  for( ; n > 0; n /= 2){
    if(n % 2 == 1){
      MatrixMulplication(A, B, B);
    }
    MatrixMulplication(A, A, A);
  }
}

int GetMappedValue(int x, int y){
  return x * K + y;
}

void Initialise(){
  for(int x = 0; x < K; ++x){
    for(int y = 0; y < K; ++y){
      int i = GetMappedValue(x, y);
      vector<int> v;

      for(pii move: moves){
        auto [dx, dy] = move;
        int nx = x + dx, ny = y + dy;

        if(nx < 0 || ny < 0 || nx >= K || ny >= K){
          continue;
        }

        v.push_back(GetMappedValue(nx, ny));
      }

      for(int j: v){
        A[i][j] = 1.0 / v.size();
      }

      B[i][i] = 1;
    }
  }
}

int main(){
  Initialise();

  int n;
  cin >> n;
  MatrixExponentiation(n, A, B);

  double ans = 0;
  for(int j = 0; j < N; ++j){
    double ansx = 1;
    for(int i = 0; i < N; ++i){
      ansx *= (1 - B[i][j]);
    }
    ans += ansx;
  }

  printf("%lf\n", ans);

  return 0;
}