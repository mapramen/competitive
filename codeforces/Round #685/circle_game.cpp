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

bool Solve(){
  ll d, k;
  scanf("%lld%lld", &d, &k);

  ll m = 0;
  for(ll x = 0; x <= d; x += k){
    ll y = sqrt(d * d - x * x);
    for( ; x * x + y * y <= d * d; ++y);
    --y;
    m = max(m, x + y);
  }

  return (m / k) % 2 != 0;
}

int main(){
  int t;
  scanf("%d", &t);
  while(t--){
    printf("%s\n", Solve() ? "Ashish" : "Jeel");
  }
  return 0;
}