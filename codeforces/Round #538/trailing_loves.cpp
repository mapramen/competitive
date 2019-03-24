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

ll Calculate(ll n, ll &b, ll p){
  ll x = 0, y = 0;
  
  for( ; b % p == 0; b /= p, ++x);

  for(; n > 0; n /= p){
    y += (n / p);
  }

  return y / x;
}

int main(){
  ll n, b;
  ll ans = LLONG_MAX;

  cin >> n >> b;

  for(ll i = 2; i * i <= b; ++i){
    if(b % i != 0){
      continue;
    }
    ans = min(ans, Calculate(n, b, i));
  }

  if(b > 1){
    ans = min(ans, Calculate(n, b, b));
  }

  cout << ans << '\n';
  
  return 0;
}