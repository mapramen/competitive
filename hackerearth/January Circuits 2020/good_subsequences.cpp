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
#define M 1024
#define MOD 1000000007

int c[M];
ll dp[2][M];

int GetMask(int x){
  int mask = 0;
  for( ; x > 0; x /= 10){
    mask |= (1 << (x % 10));
  }
  return mask;
}

int main(){
  int n;

  scanf("%d", &n);
  while(n--){
    int x;
    scanf("%d", &x);
    ++c[GetMask(x)];
  }

  int cur = 0;
  dp[cur][0] = 1;
  for(int i = 1; i < M; ++i){
    if(c[i] == 0){
      continue;
    }
    
    int nxt = 1 - cur;
    for(int j = 0; j < M; ++j){
      dp[nxt][j] = dp[cur][j];
    }

    for(int j = 0; j < M; ++j){
      if((i & j) > 0){
        continue;
      }
      int k = i | j;
      dp[nxt][k] = (dp[nxt][k] + c[i] * dp[cur][j]) % MOD;
    }
    cur = nxt;
  }

  int ans = 0;
  for(int j = 1; j < M; ++j){
    ans = (ans + dp[cur][j]) % MOD;
  }

  printf("%d\n", ans);

  return 0;
}