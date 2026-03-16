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
#define LOGN 18

int a[2 * N], T[LOGN][2 * N];

void PreProcess(int n){
  for(int k = 1; k < LOGN; ++k){
    for(int i = 1; i <= n; ++i){
      T[k][i] = T[k - 1][min(n, T[k - 1][i] + 1)];
    }
  }
}

int Query(int i, int j){
  int ans = 0;
  for(int k = LOGN - 1; k > -1; --k){
    int ix = T[k][i] + 1;
    if(ix <= j){
      ans += (1 << k);
      i = ix;
    }
  }
  return 1 + ans;
}

int main(){
  int n;
  ll m;

  scanf("%d%lld", &n, &m);
  for(int i = 1; i <= n; ++i){
    scanf("%d", &a[i]);
  }

  for(int i = 1, j = n + 1; i < n; ++i, ++j){
    a[j] = a[i];
  }

  for(int i = 2 * n - 1, j = i, s = 0; i > 0; --i){
    s += a[i];
    for( ; s > m; s -= a[j], --j);
    T[0][i] = j;
  }

  PreProcess(2 * n - 1);

  int ans = INT_MAX;
  for(int i = 1, j = n; i <= n; ++i, ++j){
    ans = min(ans, Query(i, j));
  }

  printf("%d\n", ans);

  return 0;
}