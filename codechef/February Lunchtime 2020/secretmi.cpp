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
#define N 201
#define M 20001

const int inf = 1E9;
int a[M], w[N][N], d[N][N], dp[M];

int Solve(){
  int n, m, l;

  scanf("%d%d%d", &n, &m, &l);

  for(int i = 1; i <= n; ++i){
    for(int j = 1; j <= n; ++j){
      w[i][j] = inf;
    }
    w[i][i] = 0;
  }

  for(int i = 1; i <= l; ++i){
    scanf("%d", &a[i]);
  }

  while(m--){
    int i, j, k;
    scanf("%d%d%d", &i, &j, &k);
    w[i][j] = k;
    w[j][i] = k;
  }

  for(int i = 1; i <= n; ++i){
    for(int j = 1; j <= n; ++j){
      d[i][j] = w[i][j];
    }
  }

  for(int k = 1; k <= n; ++k){
    for(int i = 1; i <= n; ++i){
      for(int j = 1; j <= n; ++j){
        d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
      }
    }
  }

  m = l;
  dp[1] = 1;
  for(int x = 2; x <= m; ++x){
    int &ans = dp[x];
    ans = inf;

    int i = a[x], k = i;
    for(int y = x - 1; y > 0; --y){
      int j = a[y];
      if(d[i][j] != d[i][k] + w[k][j]){
        break;
      }
      ans = min(ans, 1 + dp[y]);
      k = j;
    }
  }

  return dp[m] == inf ? -1 : dp[m];
}

int main(){
  int t;

  scanf("%d", &t);
  while(t--){
    printf("%d\n", Solve());
  }

  return 0;
}