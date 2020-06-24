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
#define N 20
#define MOD 1000000007

vector<vector<int>> adj(N);
int dp[(1 << N)][N];

int main(){
  int n, m;

  scanf("%d%d", &n, &m);
  while(m--){
    int i, j;
    scanf("%d%d", &i, &j);
    adj[i - 1].push_back(j - 1);
  }

  dp[1][0] = 1;
  for(int mask = 1; mask < (1 << n); ++mask){
    for(int tmask = mask; tmask; ){
      int i = __builtin_ctz(tmask), val = dp[mask][i];
      tmask ^= (1 << i);
      
      if(val == 0){
        continue;
      }

      for(int j: adj[i]){
        if((mask & (1 << j)) > 0){
          continue;
        }
        int nmask = mask | (1 << j);
        dp[nmask][j] = (dp[nmask][j] + val) % MOD;
      }
    }
  }

  printf("%d\n", dp[(1 << n) - 1][n - 1]);

  return 0;
}