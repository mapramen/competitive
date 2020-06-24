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

int parent[N], sz[N], ansNumber, ansSize;

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

  --ansNumber;
  ansSize = max(ansSize, sz[i]);
}

int main(){
  int n, m;

  scanf("%d%d", &n, &m);

  for(int i = 1; i <= n; ++i){
    parent[i] = i;
    sz[i] = 1;
  }

  ansNumber = n, ansSize = 1;
  while(m--){
    int i, j;
    scanf("%d%d", &i, &j);
    Union(i, j);
    printf("%d %d\n", ansNumber, ansSize);
  }

  return 0;
}