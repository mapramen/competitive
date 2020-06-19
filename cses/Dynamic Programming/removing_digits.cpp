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
#define B 10

int dp[B];

int main(){
  int n;

  scanf("%d", &n);
  for(int i = 1; i <= n; ++i){
    int ans = INT_MAX;

    for(int d = B - 1; d > 0; --d){
      dp[d] = dp[d - 1];
    }

    for(int x = i; x > 0; x /= 10){
      int d = x % 10;
      if(d){
        ans = min(ans, 1 + dp[d]);
      }
    }

    dp[0] = ans;
  }

  printf("%d\n", dp[0]);

  return 0;
}