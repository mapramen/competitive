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
#define N 1001
#define MOD 1000000007

char s[N];
int dp[N];

int main(){
  int n;

  scanf("%d", &n);

  dp[1] = 1;
  for(int i = 1; i <= n; ++i){
    scanf("%s", s);
    for(int j = 1; j <= n; ++j){
      dp[j] = (s[j - 1] == '*') ? 0 : (dp[j] + dp[j - 1]) % MOD;
    }
  }

  printf("%d\n", dp[n]);
  
  return 0;
}