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
#define N 501
#define M 10000

int c[N], x[N];

void Reset(){
  for(int i = 1; i < N; ++i){
    x[i] = 0;
  }
}

void Update(int k, int s){
  if(k > 0){
    x[k] = min(M, x[k] + s);
  }
}

bool Check(int n, int a, int b, int k){
  Reset();

  Update(k, 1);
  for(k = N; k > 0; --k){
    if(x[k] < c[k]){
      return false;
    }

    int s = x[k] - c[k];
    Update(k - a, s);
    Update(k - b, s);
  }

  return true;
}

void Solve(){
  int n, a, b;
  scanf("%d%d%d", &n, &a, &b);

  for(int i = 1; i < N; ++i){
    c[i] = 0;
  }

  for(int i = 1; i <= n; ++i){
    scanf("%d", &c[i]);
  }

  for(int k = 1; k < N; ++k){
    if(Check(n, a, b, k)){
      printf("%d\n", k);
      return;
    }
  }

  printf("IMPOSSIBLE\n");
}

int main(){
  int t;
  scanf("%d", &t);
  for(int k = 1; k <= t; ++k){
    printf("Case #%d: ", k);
    Solve();
  }
  return 0;
}