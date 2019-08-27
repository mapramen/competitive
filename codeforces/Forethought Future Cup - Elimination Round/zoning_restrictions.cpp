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
#define N 52

int m, l[N], r[N], a[N], c[N], dp[N][N][N];

int inline Cost(int i, int j, int k, int h){
  int cost = h * h;
  for(int x = 1; x <= m; ++x){
    if(i <= l[x] && r[x] <= j && l[x] <= k && k <= r[x] && a[x] < h){
      cost -= c[x];
    }
  }
  return cost;
}

int main(){
  int n, h;

  cin >> n >> h >> m;
  for(int i = 1; i <= m; ++i){
    cin >> l[i] >> r[i] >> a[i] >> c[i];
  }

  for(int len = 1; len <= n; ++len){
    for(int i = 1, j = i + len - 1; j <= n; ++i, ++j){
      for(int x = 1; x <= h; ++x){
        int &ans = dp[i][j][x];
        ans = dp[i][j][x - 1];
        for(int k = i; k <= j; ++k){
          int ansx = Cost(i, j, k, x) + dp[i][k - 1][x] + dp[k + 1][j][x];
          ans = max(ans, ansx);
        }
      }
    }
  }

  cout << dp[1][n][h] << '\n';

  return 0;
}