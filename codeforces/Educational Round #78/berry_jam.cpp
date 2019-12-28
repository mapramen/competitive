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
#define BASE (N / 2)

int a[N], c[N];

int main(){
  int t;
  scanf("%d", &t);

  for(int x = 0; x < N; ++x){
    c[x] = INT_MIN;
  }
  c[BASE] = 0;

  while(t--){
    int n;
    scanf("%d", &n);
    n *= 2;

    for(int i = 1; i <= n; ++i){
      scanf("%d", &a[i]);
    }

    c[BASE] = 0;
    for(int i = 1, j = n, x = BASE; i < j; ++i, --j){
      x += (a[j] == 1 ? 1 : -1);
      c[x] = max(c[x], i);
    }

    int ans = c[BASE];
    for(int i = 1, j = n, x = BASE; i < j; ++i, --j){
      x += (a[i] == 1 ? -1 : 1);
      int ansx = i + c[x];
      ans = max(ans, ansx);
    }
    ans = n - ans;

    for(int i = 1, j = n, x = BASE; i < j; ++i, --j){
      x += (a[j] == 1 ? 1 : -1);
      c[x] = INT_MIN;
    }

    printf("%d\n", ans);
  }
  return 0;
}