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

int Query(char c, int i = 0, int j = 0){
  printf("%c ", c);

  if(i != 0){
    printf("%d ", i);
  }

  if(j != 0){
    printf("%d ", j);
  }

  printf("\n");
  fflush(stdout);
  
  int x;
  scanf("%d", &x);
  return x;
}

void Solve(int n){
  for(int i = 1; i < n; ++i){
    int x = Query('M', i, n);
    if(x != i){
      Query('S', i, x);
    }
  }

  Query('D');
}

int main(){
  int t, n;
  scanf("%d%d", &t, &n);
  for(int k = 1; k <= t; ++k){
    Solve(n);
  }
  return 0;
}