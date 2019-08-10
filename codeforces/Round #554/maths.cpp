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

ll a, b, ans = LLONG_MAX, ansK;

void UpdateAns(ll g){
  ll x = (a + g - 1) / g, y = (b + g - 1) / g;
  x *= g, y *= g;
  ll ansx = x * (y / gcd(x, y));
  if(ansx < ans || (ansx == ans && x - a < ansK)){
    ans = ansx;
    ansK = x - a;
  }
}

int main(){  
  cin >> a >> b;

  ll c = abs(a - b);
  for(ll g = 1; g * g <= c; ++g){
    if(c % g != 0){
      continue;
    }
    UpdateAns(g);
    UpdateAns(c / g);
  }

  cout << ansK << '\n';

  return 0;
}