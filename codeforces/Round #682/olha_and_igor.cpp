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

vector<int> C;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int Query(int i, int j, int k){
  printf("? %d %d %d\n", i, j, k);
  fflush(stdout);

  int x;
  scanf("%d", &x);
  ++C[x];

  return x;
}

int GetRandomInt(int n, int i, int j){
  int k = uniform_int_distribution<int>(1, n)(rng);
  while(k == i || k == j){
    k = uniform_int_distribution<int>(1, n)(rng);
  }
  return k;
}

int GetMostFrequent(int n){
  int c = 0;
  for(int i = 1; i <= n; ++i){
    c = max(c, C[i]);
  }

  int ans = 1;
  for(int i = 1; i <= n; ++i){
    if(c == C[i]){
      ans = i;
    }
  }

  return ans;
}

pii GetChildRoots(int n){
  int i = GetMostFrequent(n);
  C[i] = 0;
  int j = GetMostFrequent(n);

  return {i, j};
}

int main(){
  int h;
  scanf("%d", &h);

  int n = (1 << h) - 1;
  C.resize(n + 1);

  for(int q = 0; q < 420; ++q){
    int i = GetRandomInt(n, 0, 0);
    int j = GetRandomInt(n, i, 0);
    int k = GetRandomInt(n, i, j);

    Query(i, j, k);
  }

  auto [i, j] = GetChildRoots(n);

  int root = 1;
  for( ; ; ++root){
    if(root == i || root == j){
      continue;
    }

    if(Query(i, j, root) == root){
      break;
    }
  }

  printf("! %d\n", root);
  fflush(stdout);

  return 0;
}