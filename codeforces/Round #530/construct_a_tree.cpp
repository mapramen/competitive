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

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair

ll Compute(ll n, ll k, ll x = 1){
  ll ans = 0;
  for(ll d = 1; n; x *= k, ++d){
    ll z = min(x, n);
    ans += d * z;
    n -= z;
  }
  return ans;
}

ll ComputeMinBranchCoefficient(ll n, ll s){
  ll x = 2 * n - 1, y = (n * (n + 1)) / 2;
  
  if(s < x || s > y){
    return -1;
  }
  
  ll k = 2;
  for( ; s < Compute(n, k); ++k);

  return k;
}

ll BinarySearch(ll n, ll y, ll k, ll s){
  ll x = 1, ans = min(n, y);
  while(x <= y){
    ll mid = x + (y - x) / 2;
    if(Compute(n, k, mid) > s){
      x = mid + 1;
    }
    else{
      ans = mid, y = mid - 1;
    }
  }
  return ans;
}

int main(){
  ll n, s;

  cin >> n >> s;

  ll k = ComputeMinBranchCoefficient(n, s);

  if(k < 1){
    printf("No\n");
    return 0;
  }

  vector<ll> d(1);
  d.push_back(1);

  s -= n, --n;
  while(n){
    ll x = BinarySearch(n, min(k * d.back(), n), k, s);
    d.push_back(x);
    s -= n;
    n -= x;
  }

  printf("Yes\n");
  for(ll i = 2, p = 1; i < d.size(); p += d[i], ++i){
    ll y = d[i], q = p;
    while(y){
      ll x = min(k, y);
      y -= x;
      while(x--){
        printf("%lld ", q);
      }
      --q;
    }
  }
  printf("\n");

  return 0;
}