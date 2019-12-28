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

ll CountX(ll n, ll x){
  return max(0ll, min(n, x));
}

ll Count(ll n, ll m){
  ll ans = 0;
  for(ll x = m, y = m + (m % 2 == 0); x <= n; x = 2 * x, y = 2 * y + 1){
    ans += (CountX(n, y) - CountX(n, x - 1));
  }
  return ans;
}

ll BinarySearch(ll n, ll m, ll mod, ll k){
  ll x = 1, y = m, z = -1;

  while(x <= y){
    ll mid = x + (y - x) / 2;

    if(Count(n, 2 * mid - mod) >= k){
      z = mid, x = mid + 1;
    }
    else{
      y = mid - 1;
    }
  }

  return 2 * z - mod;
}

int main(){
  ll n, k;
  cin >> n >> k;
  
  ll m1 = n / 2, m2 = n - m1;
  cout << max(BinarySearch(n, m1, 0, k), BinarySearch(n, m2, 1, k)) << '\n';

  return 0;
}