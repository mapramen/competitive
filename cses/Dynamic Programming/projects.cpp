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

vector<tiii> v;
map<int,ll> dp;

int main(){
  int n;

  scanf("%d", &n);
  while(n--){
    int i, j, k;
    scanf("%d%d%d", &i, &j, &k);
    v.push_back({j, i, k});
  }
  sort(v.begin(), v.end());

  ll ans = 0;
  dp[0] = 0;

  for(tiii t: v){
    auto [j, i, k] = t;
    auto it = prev(dp.lower_bound(i));

    ans = max(ans, k + it->second);
    dp[j] = ans;
  }

  printf("%lld\n", ans);

  return 0;
}