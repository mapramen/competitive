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

int parent[N];

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

  scanf("%d%d", &n, &m);
  for(int i = 1; i <= n; ++i){
    parent[i] = i;
  }

  int ans = n - 1;
  while(m--){
    int i, j;
    scanf("%d%d", &i, &j);
    ans -= Union(i, j);
  }

  printf("%d\n", ans);
  for(int i = 1, j = 0; i <= n; ++i){
    if(parent[i] != i){
      continue;
    }

    if(j){
      printf("%d %d\n", j, i);
    }

    j = i;
  }

  return 0;
}