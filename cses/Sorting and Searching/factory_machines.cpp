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
#define pli pair<ll,int>
#define N 200001

int a[N];

bool Check(int n, int m, ll t){
  for(int i = 1; i <= n && m > 0; ++i){
    m -= min(1ll * m, t / a[i]);
  }
  return m <= 0;
}

ll BinarySearch(int n, int m){
  ll x = 0, y = 1E18, ans = y;
  while(x <= y){
    ll mid = x + (y - x) / 2;
    if(Check(n, m, mid)){
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

  printf("%lld\n", BinarySearch(n, m));

  return 0;
}