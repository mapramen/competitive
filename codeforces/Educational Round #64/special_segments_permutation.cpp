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
#define N 200001

int a[N], pos[N];

int Solve(int i, int l, int r){
  int s = a[i], x1, x2, y1, y2;

  if(i - l < r - i){
    x1 = l, x2 = i - 1;
    y1 = i + 1, y2 = r;
  }
  else{
    x1 = i + 1, x2 = r;
    y1 = l, y2 = i - 1;
  }

  int ans = 0;
  for(int x = x1; x <= x2; ++x){
    int y = pos[s - a[x]];
    ans += (y1 <= y && y <= y2);
  }

  return ans;
}

int main(){
  int n;

  scanf("%d", &n);
  for(int i = 1; i <= n; ++i){
    scanf("%d", &a[i]);
  }

  for(int i = 1; i <= n; ++i){
    pos[a[i]] = i;
  }

  ll ans = 0;
  set<int> S;
  S.insert(1);
  S.insert(n + 1);

  for(int x = n; x > 0; --x){
    int i = pos[x];
    
    auto it = S.upper_bound(i);
    int l = *prev(it), r = (*it) - 1;

    if(l == r){
      continue;
    }

    ans += Solve(i, l, r);

    S.insert(i);
    S.insert(i + 1);
  }

  printf("%lld\n", ans);

  return 0;
}