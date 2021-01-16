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
#define N 500001
#define MOD 1000000007

int parent[N], vsize[N];

int Find(int i){
  return parent[i] == i ? i : parent[i] = Find(parent[i]);
}

bool Union(int i, int j){
  i = Find(i), j = Find(j);

  if(i == j){
    return false;
  }

  if(j < i){
    swap(i, j);
  }

  parent[j] = i;
  vsize[i] += vsize[j];
  return true;
}

int main(){
  int n, m;
  scanf("%d%d", &n, &m);

  for(int i = 0; i <= m; ++i){
    parent[i] = i;
    vsize[i] = 1;
  }

  vector<int> v, edges;
  for(int x = 1; x <= n; ++x){
    int k;
    scanf("%d", &k);

    while(k--){
      int i;
      scanf("%d", &i);
      v.push_back(i);
    }

    if(v.size() == 1){
      v.push_back(0);
    }

    if(Union(v.front(), v.back())){
      edges.push_back(x);
    }
    v.clear();
  }

  int ans = 1;
  for(int i = 0; i <= m; ++i){
    if(parent[i] != i){
      continue;
    }

    int k = vsize[i] - 1;
    while(k--){
      ans = (2 * ans) % MOD;
    }
  }

  printf("%d %lu\n", ans, edges.size());
  for(int e: edges){
    printf("%d ", e);
  }
  printf("\n");

  return 0;
}