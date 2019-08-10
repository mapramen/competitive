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
#define N 501

int n, m, A[N][N], B[N][N];

void TakeInput(int A[N][N]){
  for(int i = 1; i <= n; ++i){
    for(int j = 1; j <= m; ++j){
      scanf("%d", &A[i][j]);
    }
  }
}

void TransformToCharacteristic(int A[N][N]){
  for(int i = 1; i < n; ++i){
    for(int j = 1; j < m; ++j){
      if(A[i][j]){
        continue;
      }
      for(int di = 0; di < 2; ++di){
        for(int dj = 0; dj < 2; ++dj){
          A[i + di][j + dj] = 1 - A[i + di][j + dj];
        }
      }
    }
  }
}

void TakeInputAndTransform(int A[N][N]){
  TakeInput(A);
  TransformToCharacteristic(A);
}

int main(){
  scanf("%d%d", &n, &m);
  TakeInputAndTransform(A);
  TakeInputAndTransform(B);

  for(int i = 1; i <= n; ++i){
    for(int j = 1; j <= m; ++j){
      if(A[i][j] != B[i][j]){
        printf("No\n");
        return 0;
      }
    }
  }

  printf("Yes\n");
  return 0;
}