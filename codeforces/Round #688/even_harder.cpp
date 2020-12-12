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
#define N 3001

int a[N], dp[N][N];

int Solve(){
  int n;
  scanf("%d", &n);

  for(int i = 1; i <= n; ++i){
    scanf("%d", &a[i]);
  }

  dp[1][1] = 0;
  for(int i = 2; i <= n; ++i){
    for(int x = i; x <= n; ++x){
      dp[i][x] = n;
    }

    for(int j = i - 1, c = 0; j > 0; --j){
      int x = j + a[j];
      if(x < i){
        continue;
      }
      dp[i][x] = min(dp[i][x], dp[j][i - 1] + c);
      ++c;
    }

    for(int x = i + 1; x <= n; ++x){
      dp[i][x] = min(dp[i][x], dp[i][x - 1]);
    }
  }

  return dp[n][n];
}

int main(){
  int t;
  scanf("%d", &t);
  while(t--){
    printf("%d\n", Solve());
  }
  return 0;
}