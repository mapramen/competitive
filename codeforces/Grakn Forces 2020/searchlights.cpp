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
#define N 2001
#define M 1000002

pii a[N], b[N];
int c[M];

void ReadCoordinates(int n, pii a[]){
  for(int i = 1; i <= n; ++i){
    scanf("%d%d", &a[i].first, &a[i].second);
  }
}

int main(){
  int n, m;
  scanf("%d%d", &n, &m);

  ReadCoordinates(n, a);
  ReadCoordinates(m, b);

  for(int i = 1; i <= n; ++i){
    for(int j = 1; j <= m; ++j){
      int x = b[j].first - a[i].first + 1;
      int y = b[j].second - a[i].second + 1;

      if(x <= 0 || y <= 0){
        continue;
      }

      c[x] = max(c[x], y);
    }
  }

  for(int x = M - 1, y = 0; x >= 0; --x){
    int cy = c[x];
    c[x] = y;
    y = max(y, cy);
  }

  int ans = INT_MAX;
  for(int x = 0; x < M; ++x){
    ans = min(ans, x + c[x]);
  }

  printf("%d\n", ans);

  return 0;
}