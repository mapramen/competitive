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
#define N 2001
#define MOD 998244353

ll dp[2 * N][N][2];

ll ModularExponentation(ll a, ll n){
  ll ans = 1 % MOD;
  for( ; n; n /= 2){
    if(n % 2){
      ans = (ans * a) % MOD;
    }
    a = (a * a) % MOD;
  }
  return ans;
}

ll ModularInverse(ll a){
  return ModularExponentation(a, MOD - 2);
}

ll Fact(int n){
  ll ans = 1;
  for(int i = 1; i <= n; ++i){
    ans = (ans * i) % MOD;
  }
  return ans;
}

void UpdateDp(ll &dpVal, ll val){
  if(val){
    dpVal = (dpVal + val) % MOD;
  }
}

int main(){
  int n, k, l;
  cin >> n >> k >> l;

  dp[0][0][0] = 1;
  for(int i = 1; i <= 2 * n + 1; ++i){
    for(int j = 0, m = min(i, n); j <= m; ++j){
      if(j >= k){
        UpdateDp(dp[i][j][1], dp[i - 1][j][0]);
      }

      if(j){
        UpdateDp(dp[i][j][0], dp[i - 1][j - 1][0]);
        UpdateDp(dp[i][j][1], dp[i - 1][j - 1][1]);
      }

      if(j <= i - 2){
        UpdateDp(dp[i][j][0], (j + 1) * dp[i - 1][j + 1][0]);
        UpdateDp(dp[i][j][1], (j + 1) * dp[i - 1][j + 1][1]);
      }
    }
  }

  ll ans = dp[2 * n + 1][0][1];

  for(int i = 1; i <= n; ++i){
    ans = (ans * 2 * i) % MOD;
  }

  ans = (ans * ModularInverse(Fact(2 * n + 1))) % MOD;
  ans = (l * ans) % MOD;

  cout << ans << '\n';

  return 0;
}