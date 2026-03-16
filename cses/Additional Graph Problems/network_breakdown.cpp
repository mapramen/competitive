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
#define M (2 * N)

int parent[N];
vector<pii> destroyedEdges;
set<pii> edges;

pii ReadEdge(){
  int i, j;
  scanf("%d%d", &i, &j);
  if(i > j){
    swap(i, j);
  }
  return {i, j};
}

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
  int n, m, k;

  scanf("%d%d%d", &n, &m, &k);

  while(m--){
    edges.insert(ReadEdge());
  }

  for(int x = 0; x < k; ++x){
    pii edge = ReadEdge();
    if(edges.count(edge) == 0){
      destroyedEdges.push_back({0, 0});
    }
    else{
      destroyedEdges.push_back(edge);
      edges.erase(edge);
    }
  }

  int c = n;
  for(int i = 1; i <= n; ++i){
    parent[i] = i;
  }

  for(auto edge: edges){
    c -= Union(edge.first, edge.second);
  }

  vector<int> ans(k);
  for(int x = k - 1; x > -1; --x){
    ans[x] = c;
    c -= Union(destroyedEdges[x].first, destroyedEdges[x].second);
  }

  for(int x: ans){
    printf("%d ", x);
  }
  printf("\n");

  return 0;
}