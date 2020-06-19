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
#define N 200001

int a[N];

ll GetLowerBound(int n, int k){
  ll s = 0;
  for(int i = 1; i <= n; ++i){
    s += a[i];
  }
  s /= k;

  for(int i = 1; i <= n; ++i){
    s = max(s, 1ll * a[i]);
  }

  return s;
}

bool Check(int n, int k, ll m){
  for(int i = 1; i <= n && k >= 0; ){
    ll s = 0;
    for( ; i <= n && s + a[i] <= m; ++i){
      s += a[i];
    }
    --k;
  }
  return k >= 0;
}

ll BinarySearch(int n, int k){
  ll x = GetLowerBound(n, k), y = 1E15, ans = y;

  while(x <= y){
    ll mid = x + (y - x) / 2;
    if(Check(n, k, mid)){
      ans = mid, y = mid - 1;
    }
    else{
      x = mid + 1;
    }
  }

  return ans;
}

int main(){
  int n, k;

  scanf("%d%d", &n, &k);
  for(int i = 1; i <= n; ++i){
    scanf("%d", &a[i]);
  }

  printf("%lld\n", BinarySearch(n, k));

  return 0;
}