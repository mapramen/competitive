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

#define pii pair< int, int >
#define pll pair< ll, ll >
#define N 200001
#define B 18
#define ALL_ONES_MASK ((1 << B) - 1)

vector< vector<int> > v(N);
int parent[N];

inline int Find(int i){
  return i == parent[i] ? i : parent[i] = Find(parent[i]);
}

inline int Union(int i, int j){
  i = Find(i), j = Find(j);

  if(i == j){
    return 0;
  }

  if(i > j){
    swap(i, j);
  }

  parent[j] = i;
  return 1;
}

inline int FormEdge(const int i, const int j){
  return Union(v[i].back(), v[j].back());
}

inline int CollectAns(const int i, const int j){
  if(i >= N || j >= N || v[i].empty() || v[j].empty()){
    return 0ll;
  }

  int ans = 0;
  for( ; v[i].size() > 1; v[i].pop_back()){
    ans += FormEdge(i, j);
  }

  for( ; v[j].size() > 1; v[j].pop_back()){
    ans += FormEdge(i, j);
  }

  ans += FormEdge(i, j);

  return ans;
}

inline ll CollectAns(const int k){
  int ans = 0;

  for(int i = k; i > 0; i = (i - 1) & k){
    int j = k ^ i;
    if(j > i){
      continue;
    }
    ans += CollectAns(i, j);
  }

  return 1ll * k * ans;
}

int main(){
  int n;

  scanf("%d", &n);
  ll ans = 0;
  for(int i = 1; i <= n; ++i){
    int x;
    scanf("%d", &x);
    v[x].push_back(i);
    parent[i] = i;
    ans -= x;
  }
  v[0].push_back(0);

  for(int k = ALL_ONES_MASK; k > -1; --k){
    ans += CollectAns(k);
  }

  printf("%lld\n", ans);

  return 0;
}