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

ll GetSmallCount(vector<ll> &v, int x){
  ll ans = 0;
  for(int i = 1; i <= x; ++i){
    ans += v[i] * ((1 << i) - 1);
  }
  return ans;
}

bool IsPossible(vector<ll> &v, ll k){
  ll s = 0;
  for(int i = 0; i < v.size(); ++i){
    s += v[i] * (1 << i);
  }
  return k <= s;
}

void Relax(vector<ll> &v, int x, int y, ll &k, ll &small, ll &ans){
  int m = (1 << (y - x));
  ll c = min(v[y], k / m);
  
  v[y] -= c;
  v[x] += c * m;
  
  k -= c * m;
  ans += c * (m - 1);
  small += c * ((1 << y) - m);
}

int RelaxUp(vector<ll> &v, int x, ll &k, ll &small, ll &ans){
  int y = x + 1;
  
  while(y < v.size() && k > 0 && (v[y] == 0 || (1 << (y - x)) <= k)){
    Relax(v, x, y, k, small, ans);
    y += (v[y] == 0);
  }
  
  return min((int)v.size() - 1, y);
}

ll RelaxDown(vector<ll> &v, int x, int y, ll &k, ll &small, ll &ansx){
  ll ans = LLONG_MAX;

  for( ; y > x && k > 0; --y){
    Relax(v, x, y, k, small, ansx);

    if(k <= small){
      ans = min(ans, ansx + k);
    }

    if(v[y] == 0){
      continue;
    }

    --v[y];
    v[y - 1] += 2;
    ++ansx;

    if(y == x + 1){
      k = max(0ll, k - 2);
      small += 2ll * ((1 << y) - 1);
    }
  }

  return min(ans, ansx + k);
}

ll Query(vector<ll> v, int x, ll k){
  if(!IsPossible(v, k)){
    return -1;
  }

  for(int i = 0; i <= x && k > 0; ++i){
    k = max(0ll, k - v[i]);
  }

  ll small = GetSmallCount(v, x);
  ll ans = 0;

  int y = RelaxUp(v, x, k, small, ans);

  return RelaxDown(v, x, y, k, small, ans);
}

int main(){
  int n, q;
  scanf("%d%d", &n, &q);

  vector<ll> v(n);
  for(int i = 0; i < n; ++i){
    scanf("%lld", &v[i]);
  }

  while(q--){
    int t, x;
    ll k;
    scanf("%d%d%lld", &t, &x, &k);

    if(t == 1){
      v[x] = k;
    }
    else{
      printf("%lld\n", Query(v, x, k));
    }
  }

  return 0;
}