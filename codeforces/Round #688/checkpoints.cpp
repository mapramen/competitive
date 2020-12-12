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

void Solve(){
  ll n;
  scanf("%lld", &n);

  if(n % 2 == 1){
    printf("-1\n");
    return;
  }

  vector<int> v;
  while(n > 0){
    int k = 0;
    ll p = 2;

    for( ; p <= n; ++k, p = 2 * p + 2);

    v.push_back(1);
    for(int i = 1; i < k; ++i){
      v.push_back(0);
    }

    n -= (p - 2) / 2;
  }

  printf("%lu\n", v.size());
  for(int i: v){
    printf("%d ", i);
  }
  printf("\n");
}

int main(){
  int t;
  scanf("%d", &t);
  while(t--){
    Solve();
  }
  return 0;
}