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
#define N 82
#define M (N * (N - 1) / 2)

vector<int> shieldPositions(1);
int dp[N][N][M];
const int inf = 1E9;

int DP(int n, int m, int k){
  if(n < m || k < 0){
    return -inf;
  }

  if(n == 0 || m == 0){
    return 0;
  }

  if(dp[n][m][k] != -1){
    return dp[n][m][k];
  }

  int kx = k - abs(n - shieldPositions[m]);

  if(kx < 0){
    dp[n][m][k] = -inf;
    return -inf;
  }

  if(m == 1){
    dp[n][m][k] = 0;
    return 0;
  }

  int ans = DP(n, m, k - 1);
  for(int nx = n - 1, i = n - m, j = 0; nx >= m - 1 && i >= 0; --nx, --i, ++j){
    ans = max(ans, i * j + DP(nx, m - 1, kx));
  }

  dp[n][m][k] = ans;

  return ans;
}

int main(){
  int n;

  scanf("%d", &n);
  for(int i = 1; i <= n; ++i){
    int x;
    scanf("%d", &x);
    if(x == 1){
      shieldPositions.push_back(i);
    }
  }
  shieldPositions.push_back(n + 1);

  int m = shieldPositions.size() - 1;
  memset(dp, -1, sizeof(dp));

  for(int k = 0; k <= n * (n - 1) / 2; ++k){
    printf("%d ", DP(n + 1, m, k));
  }
  printf("\n");

  return 0;
}