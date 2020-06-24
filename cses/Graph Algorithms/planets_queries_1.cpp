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
#define N 200001
#define LOGN 29

int T[LOGN + 1][N];

void PreProcess(int n){
  for(int k = 1; k <= LOGN; ++k){
    for(int i = 1; i <= n; ++i){
      T[k][i] = T[k - 1][T[k - 1][i]];
    }
  }
}

int Query(int i, int x){
  for(int k = 29; k > -1; --k){
    if((x & (1 << k))){
      i = T[k][i];
      x ^= (1 << k);
    }
  }
  return i;
}

int main(){
  int n, q;

  scanf("%d%d", &n, &q);

  for(int i = 1; i <= n; ++i){
    scanf("%d", &T[0][i]);
  }

  PreProcess(n);

  while(q--){
    int i, k;
    scanf("%d%d", &i, &k);
    printf("%d\n", Query(i, k));
  }
  
  return 0;
}