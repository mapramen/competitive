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
#define N 100001
#define MOD 1000000007

int parent[N], c[N];

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
  c[i] += c[j];
}

int ModularExponentation(int a, int n){
  ll x = a, y = 1;
  for( ; n; n /= 2){
    if(n % 2){
      y = (y * x) % MOD;
    }
    x = (x * x) % MOD;
  }
  return y;
}

int main(){
  int n, k;

  scanf("%d%d", &n, &k);

  for(int i = 1; i <= n; ++i){
    parent[i] = i;
    c[i] = 1;
  }

  for(int x = 1; x < n; ++x){
    int i, j, k;
    scanf("%d%d%d", &i, &j, &k);
    if(k == 0){
      Union(i, j);
    }
  }

  int ans = ModularExponentation(n, k);
  for(int i = 1; i <= n; ++i){
    if(Find(i) != i){
      continue;
    }
    ans = (ans + MOD - ModularExponentation(c[i], k)) % MOD;
  }

  printf("%d\n", ans);

  return 0;
}