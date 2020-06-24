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
#define tiii tuple<int,int,int>
#define N 2501

ll inf = 1E18;
vector<tiii> edges;
ll dp[N];
bool reachable[N];

int main(){
  int n, m;

  scanf("%d%d", &n, &m);

  while(m--){
    int i, j, k;
    scanf("%d%d%d", &i, &j, &k);
    edges.push_back({i, j, k});
  }

  for(int i = 1; i <= n; ++i){
    dp[i] = -inf;
  }

  dp[1] = 0;
  reachable[1] = true;
  ll ans;

  for(int x = 0; x <= 3 * n; ++x){
    for(auto edge: edges){
      auto [i, j, k] = edge;
      if(!reachable[i]){
        continue;
      }
      ll dj = dp[i] + k;
      if(dp[j] < dj){
        dp[j] = x < n ? dj : inf;
      }
      reachable[j] = true;
    }
    if(dp[n] != ans && x >= n){
      printf("-1\n");
      return 0;
    }
    ans = dp[n];
  }

  printf("%lld\n", ans);

  return 0;
}