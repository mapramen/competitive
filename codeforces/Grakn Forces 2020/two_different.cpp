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

void PrintOperations(int base, int k){
  for(int j = 0; j < k; ++j){
    for(int i = 0; i < (1 << k); ++i){
      int x = base + i, y = base + (i ^ (1 << j));
      if(x > y){
        continue;
      }
      printf("%d %d\n", x, y);
    }
  }
}

int main(){
  int n;
  scanf("%d", &n);

  if(n <= 2){
    printf("0\n");
    return 0;
  }

  int k = 0;
  for( ; (1 << k) < n; ++k);
  --k;

  printf("%d\n", k * (1 << k));
  PrintOperations(1, k);
  PrintOperations(n - (1 << k) + 1, k);

  return 0;
}