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
#include <chrono>
#include <random>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 401
#define M 250001

int a[N], s[M], f[M], c[M], r[M];
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

bool Check(int indx, ll v){
  int i = s[indx], j = f[indx], R = r[indx];
  ll C = c[indx], T = v;

  for( ; i < j && R >= 0; ++i){
    ll x = C * (a[i + 1] - a[i]);
    if(x > v){
      return false;
    }
    if(x > T){
      T = v;
      --R;
    }
    ll z = min(x, T);
    T -= x;
  }

  return (R >= 0);
}

ll BinarySearch(int i, ll x = 1ll){
  if(Check(i, x)){
    return x;
  }

  ll y = 2E18, ans = y;
  while(x <= y){
    ll mid = x + (y - x) / 2;
    if(Check(i, mid)){
      ans = mid, y = mid - 1;
    }
    else{
      x = mid + 1;
    }
  }
  return ans;
}

int main(){
  int n, m;
  scanf("%d%d", &n, &m);

  for(int i = 1; i <= n; ++i){
    scanf("%d", &a[i]);
  }

  for(int i = 1; i <= m; ++i){
    scanf("%d%d%d%d", &s[i], &f[i], &c[i], &r[i]);
  }

  vector<int> v;
  for(int i = 1; i <= m; ++i){
    v.push_back(i);
  }

  shuffle(v.begin(), v.end(), rng);

  ll ans = 1;
  for(int i : v){
    ans = BinarySearch(i, ans);
  }

  printf("%lld\n", ans);

  return 0;
}