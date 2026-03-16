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

int parent[N], sz[N], c[N];
bitset<N> dp;

int Find(int i){
  return i == parent[i] ? i : parent[i] = Find(parent[i]);
}

void Union(int i, int j){
  i = Find(i), j = Find(j);

  if(i == j){
    return;
  }

  if(i > j){
    swap(i, j);
  }

  parent[j] = i;
  sz[i] += sz[j];
}

int main(){
  int n, m;

  scanf("%d%d", &n, &m);

  for(int i = 1; i <= n; ++i){
    parent[i] = i;
    sz[i] = 1;
  }

  while(m--){
    int i, j;
    scanf("%d%d", &i, &j);
    Union(i, j);
  }

  for(int i = 1; i <= n; ++i){
    if(parent[i] == i){
      ++c[sz[i]];
    }
  }

  dp[0] = true;
  for(int i = 1; i <= n; ++i){
    for( ; c[i] > 2; c[i] -= 2){
      ++c[2 * i];
    }

    if(c[i] == 0){
      continue;
    }

    for(int x = 0; x < c[i]; ++x){
      dp |= (dp << i);
    }
  }

  for(int i = 1; i <= n; ++i){
    putchar('0' + dp.test(i));
  }
  putchar('\n');

  return 0;
}