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

bitset<N> dp;

int main(){
  int n;
  dp.set(0);

  scanf("%d", &n);
  while(n--){
    int x;
    scanf("%d", &x);
    dp |= (dp << x);
  }

  printf("%lu\n", dp.count() - 1);
  for(int i = 1; i < N; ++i){
    if(dp.test(i)){
      printf("%d ", i);
    }
  }
  printf("\n");

  return 0;
}