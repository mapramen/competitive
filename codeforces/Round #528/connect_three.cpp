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
#include <climits>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 1001
#define M 3

int a[M], b[M];
bool A[N][N];

void ClearTrees(int x1, int y1, int x2, int y2){
  if(x1 <= x2){
    for(int x = x1; x <= x2; ++x){
      A[x][y1] = 1;
    }
  }
  else{
    for(int x = x1; x >= x2; --x){
      A[x][y1] = 1;
    }
  }

  if(y1 <= y2){
    for(int y = y1; y <= y2; ++y){
      A[x2][y] = 1;
    }
  }
  else{
    for(int y = y1; y >= y2; --y){
      A[x2][y] = 1;
    }
  }
}

int main(){
  for(int i = 0; i < M; ++i){
    cin >> a[i] >> b[i];
  }

  int d = INT_MAX, mx, my;
  for(int x = 0; x < N; ++x){
    for(int y = 0; y < N; ++y){
      int dx = 1;
      for(int i = 0; i < M; ++i){
        dx += abs(x - a[i]) + abs(y - b[i]);
      }
      if(dx < d){
        d = dx, mx = x, my = y;
      }
    }
  }

  cout << d << '\n';
  for(int i = 0; i < M; ++i){
    ClearTrees(mx, my, a[i], b[i]);
  }

  for(int x = 0; x < N; ++x){
    for(int y = 0; y < N; ++y){
      if(A[x][y]){
        cout << x << ' ' << y  << '\n';
      }
    }
  }

  return 0;
}