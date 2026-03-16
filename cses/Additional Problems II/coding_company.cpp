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
#define M 5001
#define MOD 1000000007

int a[N], dp[2][N][M];

int main(){
  int n, m;

  cin >> n >> m;
  for(int i = 1; i <= n; ++i){
    cin >> a[i];
  }
  sort(a + 1, a + n + 1);

  int prv = 0;
  dp[prv][0][0] = 1;
  a[0] = a[1];
  for(int i = 1; i <= n; ++i){
    int cur = 1 - prv, j = a[i] - a[i - 1];

    for(int k = 0; k <= i; ++k){
      for(int x = 0; x <= m; ++x){
        dp[cur][k][x] = 0;
      }
    }

    for(int k = 1; k <= i; ++k){
      for(int x = (k - 1) * j, y = 0; x <= m; ++x, ++y){
        if(dp[prv][k - 1][y]){
          dp[cur][k][x] = dp[prv][k - 1][y];
        }
      }

      for(int x = k * j, y = 0; x <= m; ++x, ++y){
        if(dp[prv][k][y]){
          dp[cur][k][x] = (dp[cur][k][x] + 1ll * k * dp[prv][k][y]) % MOD;
        }
      }
    }

    for(int k = 0; k < i; ++k){
      for(int x = 0; x <= m; ++x){
        if(dp[cur][k + 1][x]){
          dp[cur][k][x] = (dp[cur][k][x] + dp[cur][k + 1][x]) % MOD;
        }
      }
    }

    swap(cur, prv);
  }

  int ans = 0;
  for(int j = 0; j <= m; ++j){
    ans = (ans + dp[prv][0][j]) % MOD;
  }
  cout << ans << '\n';

  return 0;
}