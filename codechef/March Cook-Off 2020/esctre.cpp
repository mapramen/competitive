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

int Query1(int i){
  printf("1 %d\n", i);
  fflush(stdout);

  int d;
  scanf("%d", &d);
  return d;
}

int Query2(int i, int d){
  printf("2 %d %d\n", i, d);
  fflush(stdout);

  int x;
  scanf("%d", &x);
  return x;
}

int Solve(){
  int h;
  scanf("%d", &h);

  int i = Query2(1, h);
  for(int x = 1; x <= h; ++x){
    i = Query2(i, Query1(i));
  }

  return i;
}

int main(){
  int t;
  scanf("%d", &t);
  while(t--){
    printf("3 %d\n", Solve());
    fflush(stdout);

    int x;
    scanf("%d", &x);
    assert(x == 1);
  }
  return 0;
}