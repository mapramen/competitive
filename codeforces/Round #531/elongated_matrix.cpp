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

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 16
#define M 10000

int a[N][M], A[N][N], B[N][N], dp[(1 << N)][N][N];

int main(){
  int n, m;

  scanf("%d%d", &n, &m);
  for(int i = 0; i < n; ++i){
    for(int j = 0; j < m; ++j){
      scanf("%d", &a[i][j]);
    }
  }

  if(n == 1){
    int ans = INT_MAX;
    for(int j = 0; j < m - 1; ++j){
      ans = min(ans, abs(a[0][j] - a[0][j + 1]));
    }
    printf("%d\n", ans);
    return 0;
  }

  for(int i = 0; i < n; ++i){
    for(int j = 0; j < n; ++j){
      if(i == j){
        continue;
      }
      int &x = A[i][j], &y = B[i][j];
      x = INT_MAX, y = INT_MAX;
      for(int k = 0; k < m; ++k){
        x = min(x, abs(a[i][k] - a[j][k]));
      }
      for(int k = 0; k < m - 1; ++k){
        y = min(y, abs(a[j][k] - a[i][k + 1]));
      }
    }
  }

  for(int i = 0; i < n; ++i){
    dp[(1 << i)][i][i] = INT_MAX;
  }

  for(int mask = 1; mask < (1 << n); ++mask){
    for(int i = 0; i < n; ++i){
      if((mask & (1 << i)) == 0){
        continue;
      }
      for(int j = 0; j < n; ++j){
        if((mask & (1 << j)) == 0){
          continue;
        }
        for(int k = 0; k < n; ++k){
          if((mask & (1 << k)) > 0){
            continue;
          }
          dp[(mask ^ (1 << k))][i][k] = max(dp[(mask ^ (1 << k))][i][k], min(dp[mask][i][j], A[j][k]));
        }
      }
    }
  }

  int ans = INT_MIN;
  for(int i = 0; i < n; ++i){
    for(int j = 0; j < n; ++j){
      if(i == j){
        continue;
      }
      ans = max(ans, min(dp[(1 << n) - 1][i][j], B[i][j]));
    }
  }

  printf("%d\n", ans);

  return 0;
}