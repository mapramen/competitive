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
#define B 6

ll c[B];

ll Cost(ll x, ll y){
  if(x == 0){
    return y >= 0 ? y * c[1] : -y * c[4];
  }

  if(y == 0){
    return x >= 0 ? x * c[5] : -x * c[2];
  }

  if(x * y < 0){
    return Cost(x, 0) + Cost(0, y);
  }

  if(x > 0){
    int z = min(x, y);
    return z * c[0] + Cost(x - z, y - z);
  }

  int z = max(x, y);
  return -z * c[3] + Cost(x - z, y - z);
}

ll Solve(){
  ll x, y;
  scanf("%lld%lld", &x, &y);

  for(int i = 0; i < B; ++i){
    scanf("%lld", &c[i]);
  }

  for(int i = 0; i < B; ++i){
    int j = (i + 1) % B;
    int k = (j + 1) % B;
    c[j] = min(c[j], c[i] + c[k]);
  }

  return Cost(x, y);
}

int main(){
  int t;
  scanf("%d", &t);
  while(t--){
    printf("%lld\n", Solve());
  }
  return 0;
}