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
#include <climits>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 100001

char s[N];
int a[N];
ll dp[4];

int main(){
  int n;

  scanf("%d%s", &n, s);
  for(int i = 1; i <= n; ++i){
    scanf("%d", &a[i]);
  }

  for(int i = 1; i < 3; ++i){
    dp[i] = 1E14;
  }

  for(int i = 1; i <= n; ++i){
    char c = s[i - 1];
    if(c == 'h'){
      dp[1] = min(dp[1], dp[0]);
      dp[0] += a[i];
    }
    else if(c == 'a'){
      dp[2] = min(dp[2], dp[1]);
      dp[1] += a[i];
    }
    else if(c == 'r'){
      dp[3] = min(dp[3], dp[2]);
      dp[2] += a[i];
    }
    else if(c == 'd'){
      dp[3] += a[i];
    }
  }

  ll ans = LLONG_MAX;
  for(int i = 0; i < 4; ++i){
    ans = min(ans, dp[i]);
  }

  printf("%lld\n", ans);

  return 0;
}