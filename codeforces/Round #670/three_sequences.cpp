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

ll a[N], B, C;

void CollectAns(int i, int dx){
  if(a[i] == 0){
    return;
  }

  if(a[i] >= 0){
    B += dx * a[i];
  }
  else{
    C -= dx * a[i];
  }
}

void PreProcess(int n){
  B = a[1], C = a[n];
  for(int i = 1; i < n; ++i){
    a[i] = a[i + 1] - a[i];
    CollectAns(i, 1);
  }
}

void Update(int n, int i, int x){
  if(i <= 0 || i >= n){
    return;
  }
  CollectAns(i, -1);
  a[i] += x;
  CollectAns(i, 1);
}

void Update(int n){
  int l, r, x;
  scanf("%d%d%d", &l, &r, &x);

  if(l == 1){
    B += x;
  }

  if(r == n){
    C += x;
  }

  Update(n, l - 1, x);
  Update(n, r, -x);
}

void PrintAns(int n){
  ll ans = max(B, C);
  if(ans % 2 == 1){
    ++ans;
  }
  printf("%lld\n", ans / 2);
}

int main(){
  int n;

  scanf("%d", &n);
  for(int i = 1; i <= n; ++i){
    scanf("%lld", &a[i]);
  }

  PreProcess(n);
  PrintAns(n);

  int q;
  scanf("%d", &q);
  while(q--){
    Update(n);
    PrintAns(n);
  }

  return 0;
}