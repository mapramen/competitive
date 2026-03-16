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
#define N 2000005
#define BASE 1000001

vector<vector<pii>> updates(N), queries(N);
int T[N];

void Update(int i, int val){
  for( ; i < N; i += (i & -i)){
    T[i] += val;
  }
}

int Query(int i){
  int ans = 0;
  for( ; i > 0; i -= (i & -i)){
    ans += T[i];
  }
  return ans;
}

int main(){
  int n;

  scanf("%d", &n);
  while(n--){
    int x1, x2, y1, y2;
    scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
    x1 += BASE, y1 += BASE, x2 += BASE, y2 += BASE;

    if(x1 == x2){
      queries[x1].push_back({y1 - 1, -1});
      queries[x2].push_back({y2, 1});
    }
    else{
      updates[x1].push_back({y1, 1});
      updates[x2 + 1].push_back({y2, -1});
    }
  }

  ll ans = 0;
  for(int i = 0; i < N; ++i){
    for(auto update: updates[i]){
      Update(update.first, update.second);
    }

    for(auto query: queries[i]){
      ans += query.second * Query(query.first);
    }
  }

  printf("%lld\n", ans);
  
  return 0;
}