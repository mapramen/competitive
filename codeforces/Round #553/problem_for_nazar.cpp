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
#define MOD 1000000007

ll OddSum(ll n){
  n %= MOD;
  return (n * n) % MOD;
}

ll EvenSum(ll n){
  n %= MOD;
  return (n * (n + 1)) % MOD;
}

ll Sum(ll n){
  ll a = 0, b = 0, x = 1;
  for(int y = 1; n; y = 1 - y, x *= 2){
    ll z = min(x, n);
    n -= z;
    if(y){
      a += z;
    }
    else{
      b += z;
    }
  }
  return (OddSum(a) + EvenSum(b)) % MOD;
}

ll Query(ll l, ll r){
  return (MOD + Sum(r) - Sum(l - 1)) % MOD;
}

int main(){
  ll l, r;
  cin >> l >> r;
  cout << Query(l, r) << '\n';
  return 0;
}