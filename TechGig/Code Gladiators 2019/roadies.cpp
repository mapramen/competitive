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
#define B 10
#define N (1 << B)

int dp[N];

int ConvertToMask(int x){
  int mask = 0;
  for( ; x > 0; x /= 10){
    int i = x % 10;
    mask |= (1 << i);
  }
  return mask;
}

int main(){
  int t;
  scanf("%d", &t);

  while(t--){
    int n;
    scanf("%d", &n);

    for(int i = 0; i < N; ++i){
      dp[i] = 0;
    }

    while(n--){
      int x;
      scanf("%d", &x);
      int i = ConvertToMask(x);
      dp[i] = max(dp[i], x);
    }

    for(int i = 0; i < N; ++i){
      for(int j = i; j; j = (j - 1) & i){
        int k = (i ^ j);
        dp[i] = max(dp[i], dp[j] + dp[k]);
      }
    }

    printf("%d\n", dp[N - 1]);
  }
  
  return 0;
}