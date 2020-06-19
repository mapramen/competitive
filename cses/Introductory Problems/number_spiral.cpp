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

int main(){
  int t;
  scanf("%d", &t);
  while(t--){
    ll x, y;
    scanf("%lld%lld", &x, &y);

    ll z = max(x, y);

    if(z % 2 == 0){
      swap(x, y);
    }

    ll ans = (z - 1) * (z - 1);

    if(x == z){
      ans += y;
    }
    else{
      ans += (z + z - x);
    }

    printf("%lld\n", ans);
  }
  return 0;
}