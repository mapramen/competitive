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
#define N 31
#define M 1501

int a[N], dp[M];

void Relax(int n, int m){
  for(int i = n; i > 0; --i){
    for(int j = 1; j <= min(m, i); ++j){
      dp[i] = max(dp[i], a[j] + dp[i - j]);
    }
  }
}

int Solve(){
  int n, k, m;

  scanf("%d%d%d", &n, &k, &m);

  for(int i = 0; i <= m; ++i){
    dp[i] = 0;
  }
  
  while(n--){
    for(int j = 1; j <= k; ++j){
      scanf("%d", &a[j]);
      a[j] += a[j - 1];
    }
    Relax(m, k);
  }

  return dp[m];
}

int main(){
  int t;
  scanf("%d", &t);
  for(int k = 1; k <= t; ++k){
    printf("Case #%d: %d\n", k, Solve());
  }
  return 0;
}