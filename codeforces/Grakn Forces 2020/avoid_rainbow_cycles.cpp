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
#define N 200001

int c[N], parent[N];
vector<tiii> edges;

int Find(int i){
  return parent[i] == i ? i : parent[i] = Find(parent[i]);
}

bool Union(int i, int j){
  i = Find(i), j = Find(j);
  
  if(i == j){
    return false;
  }

  if(i > j){
    swap(i, j);
  }

  parent[j] = i;
  return true;
}

int main(){
  int n, m;

  scanf("%d%d", &m, &n);

  for(int i = 1; i <= n + m; ++i){
    scanf("%d", &c[i]);
  }

  for(int i = 1; i <= m; ++i){
    int s;
    scanf("%d", &s);
    while(s--){
      int j;
      scanf("%d", &j);
      j += m;
      edges.push_back({c[i] + c[j], i, j});
    }
  }
  sort(edges.begin(), edges.end(), greater<tiii>());

  for(int i = 1; i <= n + m; ++i){
    parent[i] = i;
  }

  ll ans = 0;
  for(auto edge: edges){
    auto[w, i, j] = edge;

    if(!Union(i, j)){
      ans += w;
    }
  }

  printf("%lld\n", ans);

  return 0;
}