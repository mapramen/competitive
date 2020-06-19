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
#define N 501

int dp[N][N];

int DP(int n, int m){
  if(n == m){
    return 0;
  }

  if(n > m){
    swap(n, m);
  }

  if(dp[n][m] != 0){
    return dp[n][m];
  }

  int ans = INT_MAX;
  
  for(int x = 1; x < n; ++x){
    ans = min(ans, DP(x, m) + DP(n - x, m));
  }

  for(int y = 1; y < m; ++y){
    ans = min(ans, DP(n, y) + DP(n, m - y));
  }

  dp[n][m] = ++ans;
  return ans;
}

int main(){
  int n, m;
  cin >> n >> m;
  cout << DP(n, m) << '\n';
  return 0;
}