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
#define tiii tuple<int,int,int>
#define N 101

int a[N][N];

void Solve(){
  int n, m;
  vector<tiii> v;

  scanf("%d%d", &n, &m);
  
  for(int i = 1; i <= n; ++i){
    for(int j = 1; j <= m; ++j){
      scanf("%d", &a[i][j]);
      v.push_back({a[i][j], i, j});
    }
  }

  sort(v.begin(), v.end());

  int y = 0, c = 0;
  for(auto t: v){
    auto [x, i, j] = t;
    c ^= (x != y);
    y = x;

    if((i + j) % 2 == c){
      ++a[i][j];
    }
  }
  v.clear();

  for(int i = 1; i <= n; ++i){
    for(int j = 1; j <= m; ++j){
      printf("%d ", a[i][j]);
    }
    printf("\n");
  }
}

int main(){
  int t;
  scanf("%d", &t);
  while(t--){
    Solve();
  }
  return 0;
}