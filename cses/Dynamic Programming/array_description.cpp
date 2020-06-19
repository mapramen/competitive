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
#define N 101
#define MOD 1000000007

int dp[2][N];

int main(){
  int n, m;

  scanf("%d%d", &n, &m);

  int prv = 0;
  for(int i = 1; i <= n; ++i){
    int x;
    scanf("%d", &x);

    int cur = 1 - prv;
    int l = (x == 0) ? 1 : x;
    int r = (x == 0) ? m : x;

    for(int j = 1; j <= m; ++j){
      if(j < l || r < j){
        dp[cur][j] = 0;
        continue;
      }

      if(i == 1){
        dp[cur][j] = 1;
        continue;
      }

      int ans = (dp[prv][j - 1] + dp[prv][j]) % MOD;

      if(j < m){
        ans = (ans + dp[prv][j + 1]) % MOD;
      }

      dp[cur][j] = ans;
    }

    swap(cur, prv);
  }

  int ans = 0;
  for(int j = 1; j <= m; ++j){
    ans = (ans + dp[prv][j]) % MOD;
  }

  printf("%d\n", ans);

  return 0;
}