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
#define M 6
#define MOD 1000000007

int dp[M];

int main(){
  int n;

  scanf("%d", &n);

  dp[M - 1] = 1;
  while(n--){
    int ans = 0;
    for(int i = 0; i < M; ++i){
      ans = (ans + dp[i]) % MOD;
    }

    for(int i = 0; i + 1 < M; ++i){
      dp[i] = dp[i + 1];
    }

    dp[M - 1] = ans;
  }

  printf("%d\n", dp[M - 1]);

  return 0;
}