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
#define N 51

char s[N];
bool dp[N][N];

void Solve(){
  int n;
  scanf("%d", &n);

  for(int i = 1; i <= n; ++i){
    for(int j = 1; j <= n; ++j){
      dp[i][j] = false;
    }
    dp[i][i] = true;

    if(i){
      dp[i][i - 1] = true;
    }

    if(i < n){
      dp[i][i + 1] = true;
    }
  }

  scanf("%s", s);
  for(int i = 1; i <= n; ++i){
    if(s[i - 1] == 'Y'){
      continue;
    }
    for(int j = 1; j <= n; ++j){
      if(j != i){
        dp[j][i] = false;
      }
    }
  }

  scanf("%s", s);
  for(int i = 1; i <= n; ++i){
    if(s[i - 1] == 'Y'){
      continue;
    }
    for(int j = 1; j <= n; ++j){
      if(j != i){
        dp[i][j] = false;
      }
    }
  }

  for(int i = 1; i <= n; ++i){
    for(int j = 1; j <= n; ++j){
      for(int k = 1; k <= n; ++k){
        dp[i][j] = (dp[i][j] || (dp[i][k] && dp[k][j]));
      }
    }
  }

  for(int i = 1; i <= n; ++i){
    for(int j = 1; j <= n; ++j){
      putchar(dp[i][j] ? 'Y' : 'N');
    }
    putchar('\n');
  }
}

int main(){
  int t;
  scanf("%d", &t);
  for(int k = 1; k <= t; ++k){
    printf("Case #%d:\n", k);
    Solve();
  }
  return 0;
}