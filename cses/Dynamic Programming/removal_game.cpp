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
#define N 5001

int a[N];
ll dp[2][N];

int main(){
  int n;
  ll ans = 0;

  scanf("%d", &n);
  for(int i = 1; i <= n; ++i){
    scanf("%d", &a[i]);
    ans += a[i];
  }

  int prv = 0;
  for(int i = 1; i <= n; ++i){
    dp[prv][i] = a[i];
  }

  for(int l = 2; l <= n; ++l){
    int cur = 1 - prv;

    for(int i = 1, j = l; j <= n; ++i, ++j){
      dp[cur][i] = max(a[i] - dp[prv][i + 1], a[j] - dp[prv][i]);
    }

    swap(cur, prv);
  }

  ans = (ans + dp[prv][1]) / 2;

  printf("%lld\n", ans);

  return 0;
}