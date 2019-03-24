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
#define N 5001
#define B 2

int a[N], dp[N][N][B];

int Compute(int i, int j, int c){
  int ans = INT_MAX;
  for(int x = 0; x < B; ++x){
    int d = (x == 0) ? a[i] : a[j];
    ans = min(ans, dp[i][j][x] + (c != d));
  }
  return ans;
}

int main(){
  int n;

  cin >> n;
  for(int i = 1; i <= n; ++i){
    cin >> a[i];
  }

  for(int k = 2; k <= n; ++k){
    for(int i = 1; i <= n - k + 1; ++i){
      int j = i + k - 1;
      dp[i][j][0] = Compute(i + 1, j, a[i]);
      dp[i][j][1] = Compute(i, j - 1, a[j]);
    }
  }

  int ans = n - 1;
  for(int x = 0; x < B; ++x){
    ans = min(ans, dp[1][n][x]);
  }

  cout << ans << '\n';

  return 0;
}