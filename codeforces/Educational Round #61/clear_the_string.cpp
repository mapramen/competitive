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
#define N 501

int dp[N][N];

int main(){
  int n;
  string s;

  cin >> n >> s;

  for(int i = 1; i <= n; ++i){
    dp[i][i] = 1;
  }

  for(int l = 2; l <= n; ++l){
    for(int i = 1, j = i + l - 1; j <= n; ++i, ++j){
      dp[i][j] = 1 + dp[i + 1][j];
      for(int k = i + 1; k <= j; ++k){
        if(s[k - 1] == s[i - 1]){
          dp[i][j] = min(dp[i][j], dp[i + 1][k - 1] + dp[k][j]);
        }
      }
    }
  }

  printf("%d\n", dp[1][n]);

  return 0;
}