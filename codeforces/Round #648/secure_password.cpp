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
#define N 1001
#define Q 13

vector<vector<int>> V(Q);
int assignedMask[N];
ll queryAns[Q], ans[N];

ll Query(vector<int> &v){
  if(v.empty()){
    return 0;
  }

  printf("? %lu ", v.size());
  for(auto x: v){
    printf("%d ", x);
  }
  printf("\n");
  fflush(stdout);

  ll x;
  scanf("%lld", &x);
  return x;
}

int main(){
  int n;

  scanf("%d", &n);

  for(int i = 1, mask = 0; mask < (1 << Q) && i <= n; ++mask){
    if(__builtin_popcount(mask) != (Q / 2)){
      continue;
    }

    assignedMask[i] = mask;

    for(int k = 0; k < Q; ++k){
      if((mask & (1 << k)) == 0){
        continue;
      }
      V[k].push_back(i);
    }

    ++i;
  }

  for(int k = 0; k < Q; ++k){
    queryAns[k] = Query(V[k]);
  }

  for(int i = 1; i <= n; ++i){
    for(int mask = (((1 << Q) - 1) ^ assignedMask[i]); mask; ){
      int k = __builtin_ctz(mask);
      ans[i] |= queryAns[k];
      mask ^= (1 << k);
    }
  }

  printf("! ");
  for(int i = 1; i <= n; ++i){
    printf("%lld ", ans[i]);
  }
  printf("\n");
  fflush(stdout);

  return 0;
}