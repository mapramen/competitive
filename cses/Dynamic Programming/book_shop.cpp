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
#define N 100001

int dp[N];

int main(){
  int n, m;

  scanf("%d%d", &m, &n);

  vector<pii> v(m);
  for(int i = 0; i < m; ++i){
    scanf("%d", &v[i].first);
  }

  for(int i = 0; i < m; ++i){
    scanf("%d", &v[i].second);
  }

  for(pii p: v){
    auto [x, c] = p;
    for(int i = n; i >= x; --i){
      dp[i] = max(dp[i], c + dp[i - x]);
    }
  }

  int ans = 0;
  for(int i = 0; i <= n; ++i){
    ans = max(ans, dp[i]);
  }

  printf("%d\n", ans);
  
  return 0;
}