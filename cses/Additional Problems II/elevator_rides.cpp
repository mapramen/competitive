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

int a[N], dp[(1 << N)], W;

inline void Update(int &x, int val){
  if(val > W){
    return;
  }
  x = min(x, val);
}

int main(){
  int n;

  cin >> n >> W;

  for(int i = 0; i < n; ++i){
    cin >> a[i];
  }

  for(int mask = 0; mask < (1 << n); ++mask){
    dp[mask] = INT_MAX;
  }

  int cmask = (1 << n) - 1;

  dp[0] = 0;
  for(int x = 1; x <= n; ++x){
    for(int mask = 0; mask < (1 << n); ++mask){
      if(dp[mask] != INT_MAX){
        dp[mask] = 0;
      }
    }


    for(int mask = 0; mask < (1 << n); ++mask){
      if(dp[mask] == INT_MAX){
        continue;
      }

      int tmask = cmask ^ mask;
      while(tmask != 0){
        int k = __builtin_ctz(tmask);
        int nmask = mask | (1 << k);
        Update(dp[nmask], dp[mask] + a[k]);
        tmask ^= (1 << k);
      }
    }

    if(dp[cmask] != INT_MAX){
      cout << x << '\n';
      break;
    }
  }

  return 0;
}