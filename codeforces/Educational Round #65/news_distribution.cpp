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
#define N 500001

int parent[N], s[N];

int Find(int i){
  return parent[i] == i ? i : parent[i] = Find(parent[i]);
}

void Union(int i, int j){
  i = Find(i), j = Find(j);
  if(i == j){
    return ;
  }

  if(i > j){
    swap(i, j);
  }

  parent[j] = i;
  s[i] += s[j];
}

int main(){
  int n, m;

  scanf("%d%d", &n, &m);

  for(int i = 1; i <= n; ++i){
    parent[i] = i;
    s[i] = 1;
  }

  while(m--){
    int k;
    scanf("%d", &k);

    if(k == 0){
      continue;
    }

    int i;
    scanf("%d", &i);
    while(--k){
      int j;
      scanf("%d", &j);
      Union(i, j);
    }
  }

  for(int i = 1; i <= n; ++i){
    printf("%d ", s[Find(i)]);
  }
  printf("\n");

  return 0;
}