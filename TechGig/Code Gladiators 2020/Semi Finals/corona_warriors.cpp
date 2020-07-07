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
#define N 21
#define M 10

int a[M][N], dp[N][(1 << M)];
const int inf = 1E9;

int main(){
  int n, m;

  cin >> n >> m;
  for(int j = 0; j < m; ++j){
    for(int i = 1; i <= n; ++i){
      cin >> a[j][i];
    }
  }

  for(int i = 0, mask = 0; mask < (1 << m); ++mask){
    dp[i][mask] = inf;
  }

  dp[0][0] = 0;
  for(int i = 1; i <= n; ++i){
    for(int mask = 0; mask < (1 << m); ++mask){
      int ans = inf;
      for(int tmask = mask; tmask > 0; ){
        int k = __builtin_ctz(tmask);
        int nmask = (mask ^ (1 << k));

        for(int j = i, s = 0; j > 0; --j){
          s += a[k][j];
          ans = min(ans, s + dp[j - 1][nmask]);
        }

        tmask ^= (1 << k);
      }
      dp[i][mask] = ans;
    }
  }

  int ans = inf;
  for(int mask = 0; mask < (1 << m); ++mask){
    ans = min(ans, dp[n][mask]);
  }

  cout << ans << '\n';

  return 0;
}