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

int rows[N], columns[N];
int parent[N], vsize[N], esize[N];

void Initialise(int n, int m){
  for(int i = 1; i <= n; ++i){
    rows[i] = 0;
    columns[i] = 0;
  }

  for(int i = 1; i <= m; ++i){
    parent[i] = i;
    vsize[i] = 1;
    esize[i] = 0;
  }
}

int Find(int i){
  return i == parent[i] ? i : parent[i] = Find(parent[i]);
}

void Union(int i, int j){
  if(i == 0 || j == 0){
    return;
  }

  i = Find(i), j = Find(j);

  if(i == j){
    ++esize[i];
    return;
  }

  if(i > j){
    swap(i, j);
  }

  parent[j] = i;
  vsize[i] += vsize[j];
  esize[i] += (1 + esize[j]);
}

int Solve(){
  int n, m;
  scanf("%d%d", &n, &m);

  Initialise(n, m);
  
  int ans = 0;
  for(int i = 1; i <= m; ++i){
    int x, y;
    scanf("%d%d", &x, &y);

    if(x == y){
      continue;
    }

    columns[x] = i;
    rows[y] = i;
    ++ans;
  }

  for(int i = 1; i <= n; ++i){
    Union(rows[i], columns[i]);
  }

  for(int i = 1; i <= m; ++i){
    ans += (parent[i] == i && esize[i] >= vsize[i]);
  }

  return ans;
}

int main(){
  int t;
  scanf("%d", &t);
  while(t--){
    printf("%d\n", Solve());
  }
  return 0;
}