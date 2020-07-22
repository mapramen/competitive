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

int main(){
  int n, s = 0;
  priority_queue<pii> Q;

  scanf("%d", &n);
  for(int i = 1; i <= n; ++i){
    int d;
    scanf("%d", &d);
    Q.push({d, i});
    s += d;

    if(d < 0){
      printf("NO\n");
      return 0;
    }
  }

  if(s % 2 == 1){
    printf("IMPOSSIBLE\n");
    return 0;
  }

  vector<pii> edges;
  while(Q.top().first != 0){
    auto [d, i] = Q.top();
    Q.pop();

    if(d > Q.size()){
      edges.clear();
      break;
    }

    vector<pii> v;
    for(int x = 1; x <= d; ++x, Q.pop()){
      pii p = Q.top();
      if(p.first == 0){
        edges.clear();
        v.clear();
        break;
      }
      edges.push_back({i, p.second});
      v.push_back({p.first - 1, p.second});
    }

    for(auto p: v){
      Q.push(p);
    }

    v.clear();
  }

  if(edges.empty()){
    printf("IMPOSSIBLE\n");
    return 0;
  }

  printf("%lu\n", edges.size());
  for(auto edge: edges){
    printf("%d %d\n", edge.first, edge.second);
  }

  return 0;
}