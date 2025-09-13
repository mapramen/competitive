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

int a[N][N];

ll Solve(){
  int n;
  scanf("%d", &n);

  for(int i = 0; i < n; ++i){
    for(int j = 0; j < n; ++j){
      scanf("%d", &a[i][j]);
    }
  }

  ll ans = 0;
  for(int k = -(n - 1); k < n; ++k){
    int x1 = max(0, k), x2 = n - 1 + min(0, k);

    ll s = 0;
    for(int x = x1, y = x1 - k; x <= x2; ++x, ++y){
      s += a[x][y];
    }

    ans = max(ans, s);
  }

  return ans;
}

int main(){
  int t;
  scanf("%d", &t);
  for(int k = 1; k <= t; ++k){
    printf("Case #%d: %lld\n", k, Solve());
  }
  return 0;
}