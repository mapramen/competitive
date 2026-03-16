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
#define B 10
#define L 19

ll p[L];

void Initialise(){
  p[0] = 1;
  for(int i = 1; i < L; ++i){
    p[i] = B * p[i - 1];
  }
}

ll Count2(int l, int c){
  return c * p[l] + l * p[l - 1];
}

ll Count1(int l, int d){
  ll ans = Count2(l, 0);
  if(d == 0){
    ans -= ((p[l] - 1) / (B - 1));
  }
  return ans;
}

ll Count(ll m, int d){
  vector<int> v;
  for( ; m != 0; m /= B){
    v.push_back((m % B));
  }
  reverse(v.begin(), v.end());

  int n = v.size(), c = 0;
  ll ans = Count1(n - 1, d);
  for(int i = 0, l = n - 1; i < n; ++i, --l){
    for(int x = (i == 0); x < v[i]; ++x){
      c += (x == d);
      ans += Count2(l, c);
      c -= (x == d);
    }
    c += (v[i] == d);
  }
  ans += c;

  return ans;
}

bool Check(ll m, ll n){
  for(int d = 0; d < B; ++d){
    if(Count(m, d) > n){
      return false;
    }
  }
  return true;
}

ll BinarySearch(ll n){
  ll x = 1, y = 1E18, ans = 1;
  while(x <= y){
    ll mid = x + (y - x) / 2;
    if(Check(mid, n)){
      ans = mid, x = mid + 1;
    }
    else{
      y = mid - 1;
    }
  }
  return ans;
}

ll Solve(ll n){
  return BinarySearch(n);
}

int main(){
  ll n;
  cin >> n;
  Initialise();
  cout << Solve(n) << '\n';
  return 0;
}