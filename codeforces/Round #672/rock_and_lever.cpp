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
#define B 32

int c[B];

ll Solve(){
  int n;
  ll ans = 0;

  for(int k = 0; k < B; ++k){
    c[k] = 0;
  }
  
  scanf("%d", &n);
  for(int i = 1; i <= n; ++i){
    int k;
    scanf("%d", &k);
    k = 32 - __builtin_clz(k);
    ans += c[k];
    ++c[k];
  }

  return ans;
}

int main(){
  int t;
  scanf("%d", &t);
  while(t--){
    printf("%lld\n", Solve());
  }
  return 0;
}