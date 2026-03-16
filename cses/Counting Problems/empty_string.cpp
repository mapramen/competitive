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
#define MOD 1000000007
 
char s[N];
int c[N][N], dp[N][N];
 
bool AreCharactersSame(int i, int j){
  return s[i - 1] == s[j - 1];
}
 
int DP(int i, int j){
  if(i > j){
    return 1;
  }
 
  if(i % 2 == j % 2){
    return 0;
  }
 
  if(j == i + 1){
    return AreCharactersSame(i, j);
  }
 
  if(dp[i][j] != -1){
    return dp[i][j];
  }
 
  int x = (j - i + 1) / 2, ans = 0;
  for(int k = i, y = 0; k < j; k += 2, ++y){
    if(AreCharactersSame(k, j)){
      int ansx = (1ll * DP(i, k - 1) * DP(k + 1, j - 1)) % MOD;
      ans = (ans + 1ll * c[x][y] * ansx) % MOD;
    }
  }
 
  dp[i][j] = ans;
  return ans;
}
 
int main(){
  scanf("%s", s);
 
  int n = strlen(s);
 
  for(int i = 0; i <= n; ++i){
    c[i][0] = 1;
    for(int j = 1; j <= i; ++j){
      c[i][j] = (c[i - 1][j - 1] + c[i - 1][j]) % MOD;
    }
  }
 
  for(int i = 1; i <= n; ++i){
    for(int j = i; j <= n; ++j){
      dp[i][j] = -1;
    }
  }
 
  printf("%d\n", DP(1, n));
 
  return 0;
}