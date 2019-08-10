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
#define tiii tuple< int, int, int >
#define N 101

int Query(int n){
  printf("%d\n", n);
  fflush(stdout);
  scanf("%d", &n);
  return n;
}

tiii Solve(int a, int b, int c, int s){
  for(int i = 1, x = 0; i < N; ++i, x += a){
    for(int j = 0, y = x; j < N; ++j, y += b){
      for(int k = 0, z = y; k < N; ++k, z += c){
        if(z == s){
          return make_tuple(i, j, k);
        }
      }
    }
  }
  return make_tuple(0, 0, 0);
}

void Solve(){
  int n1 = Query(9);
  int n2 = Query(10);

  int x1, x2, x3, x4, x5, x6;
  tie(x1, x2, x5) = Solve((1 << 9), (1 << 4), (1 << 1), n2 - n1);
  tie(x3, x4, x6) = Solve((1 << 3), (1 << 2), (1 << 1), 2 * n1 - n2);

  printf("%d %d %d %d %d %d\n", x1, x2, x3, x4, x5, x6);
  fflush(stdout);
}

int main(){
  int t, w;
  scanf("%d%d", &t, &w);
  for(int i = 1; i <= t; ++i){
    Solve();
  }
  return 0;
}