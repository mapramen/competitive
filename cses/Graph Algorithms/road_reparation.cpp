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
#define N 100001

int parent[N];
vector<tiii> edges;

int Find(int i){
  return i == parent[i] ? i : parent[i] = Find(parent[i]);
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

  scanf("%d%d", &n, &m);
  while(m--){
    int i, j, k;
    scanf("%d%d%d", &i, &j, &k);
    edges.push_back({k, i, j});
  }
  sort(edges.begin(), edges.end());

  for(int i = 1; i <= n; ++i){
    parent[i] = i;
  }

  m = 0;
  ll ans = 0;
  for(auto edge: edges){
    auto [k, i, j] = edge;
    bool ansx = Union(i, j);
    if(ansx){
      ans += k, ++m;
    }
  }

  if(m != n - 1){
    printf("IMPOSSIBLE\n");
    return 0;
  }

  printf("%lld\n", ans);

  return 0;
}