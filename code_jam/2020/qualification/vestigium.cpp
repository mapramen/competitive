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
#define N 101

int a[N][N], b[N];

void Solve(){
  int n;

  scanf("%d", &n);
  
  for(int i = 1; i <= n; ++i){
    for(int j = 1; j <= n; ++j){
      scanf("%d", &a[i][j]);
    }
  }

  int t = 0, r = 0, c = 0;
  for(int i = 1; i <= n; ++i){
    t += a[i][i];
  }

  for(int i = 1; i <= n; ++i){
    for(int j = 1; j <= n; ++j){
      b[j] = 0;
    }

    for(int j = 1; j <= n; ++j){
      ++b[a[i][j]];
    }

    for(int j = 1; j <= n; ++j){
      if(b[j] > 1){
        ++r;
        break;
      }
    }
  }

  for(int i = 1; i <= n; ++i){
    for(int j = 1; j <= n; ++j){
      b[j] = 0;
    }

    for(int j = 1; j <= n; ++j){
      ++b[a[j][i]];
    }

    for(int j = 1; j <= n; ++j){
      if(b[j] > 1){
        ++c;
        break;
      }
    }
  }

  printf("%d %d %d\n", t, r, c);
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