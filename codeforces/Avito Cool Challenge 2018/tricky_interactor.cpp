#include <stdio.h>
#include <assert.h>
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
#include <climits>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 301

int a[N];

int Query(int l, int r){
  printf("? %d %d\n", l, r);
  fflush(stdout);
  int x;
  scanf("%d", &x);
  return x;
}

int QueryFor(int n, int t, int l, int r, bool tillLeft){
  assert((l + r + n) % 2 == 0);

  int detectParity = tillLeft ? r % 2 : (n - l + 1) % 2;

  int c[2] = {0, 0}, ans;
  for(int y = t, x; c[1 - detectParity] % 2 == 1 || c[detectParity] % 2 == 0; ){
    x = Query(l, r);
    ++c[(x + y) % 2];
    y = x;
    ans = x;
  }

  return ans;
}

int QueryForAndReset(int n, int t, int l, int r, bool tillLeft){
  int x = QueryFor(n, t, l, r, tillLeft);
  QueryFor(n, x, l, r, tillLeft);
  int len = tillLeft ? r : (n - l + 1);
  return (t - x + len) / 2;
}

int QueryForLeft(int n, int t, int l, int r){
  return QueryForAndReset(n, t, l, r, true);
}

int QueryForRight(int n, int t, int l, int r){
  return QueryForAndReset(n, t, l, r, false);
}

int QueryPrefix(int n, int t, int i){
  int x;

  if(n % 2 == 1 && i == 1){
    x = QueryForLeft(n, t, 2, n) - QueryForRight(n, t, 2, n);
  }
  else{
    int l = n % 2 ? i - 1 : i;
    int r = i;
    x = QueryForLeft(n, t, l, r);
  }

  return x;
}

int main(){
  int n, t;

  scanf("%d%d", &n, &t);

  if(n == 1){
    printf("! %d\n", t);
    fflush(stdout);
    return 0;
  }

  for(int i = 1; i <= n; ++i){
    a[i] = QueryPrefix(n, t, i);
  }

  printf("! ");
  for(int i = 1; i <= n; ++i){
    printf("%d", a[i] - a[i - 1]);
  }
  printf("\n");
  fflush(stdout);
  
  return 0;
}