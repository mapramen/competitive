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
#define N 2001
#define B 10

char s[N][N];
int matrixMin[B], matrixMax[B], rowMin[B], rowMax[B], maxArea[B];

void Reset(){
  for(int d = 0; d < B; ++d){
    maxArea[d] = 0;
  }
}

void Transpose(int n){
  for(int x = 0; x < n; ++x){
    for(int y = x + 1; y < n; ++y){
      swap(s[x][y], s[y][x]);
    }
  }
}

void ResetDigitMaxMin(int minD[B], int maxD[B]){
  for(int d = 0; d < B; ++d){
    minD[d] = INT_MAX;
    maxD[d] = INT_MIN;
  }
}

void UpdateArea(int d, int area){
  if(area == 0){
    return;
  }

  maxArea[d] = max(maxArea[d], area);
}

void SolveMatrix(int n){
  ResetDigitMaxMin(matrixMin, matrixMax);

  for(int x = 0; x < n; ++x){
    for(int y = 0; y < n; ++y){
      int d = s[x][y] - '0';
      matrixMin[d] = min(matrixMin[d], x);
      matrixMax[d] = max(matrixMax[d], x);
    }
  }

  for(int x = 0; x < n; ++x){
    ResetDigitMaxMin(rowMin, rowMax);
    
    for(int y = 0; y < n; ++y){
      int d = s[x][y] - '0';
      rowMin[d] = min(rowMin[d], y);
      rowMax[d] = max(rowMax[d], y);
    }

    for(int d = 0; d < B; ++d){
      if(rowMin[d] == INT_MAX){
        continue;
      }
      UpdateArea(d, max(rowMax[d], n - 1 - rowMin[d]) * max(x - matrixMin[d], matrixMax[d] - x));
      UpdateArea(d, (rowMax[d] - rowMin[d]) * max(x, n - 1 - x));
    }
  }
}

void Solve(){
  int n;
  scanf("%d", &n);

  for(int x = 0; x < n; ++x){
    scanf("%s", s[x]);
  }

  Reset();

  for(int k = 0; k < 2; ++k, Transpose(n)){
    SolveMatrix(n);
  }

  for(int d = 0; d < B; ++d){
    printf("%d ", maxArea[d]);
  }
  printf("\n");
}

int main(){
  int t;
  scanf("%d", &t);
  while(t--){
    Solve();
  }
  return 0;
}