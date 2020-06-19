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
  ll n;
  scanf("%lld", &n);

  for(ll i = 1; i <= n; ++i){
    ll ans = (i - 1) * (i + 4) * (i * i - 3 * i + 4) / 2;
    printf("%lld\n", ans);
  }
  
  return 0;
}