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
#define N 100001

int p[N], d[N], a[N];

int main(){
  int n;

  scanf("%d", &n);

  for(int i = 2; i <= n; ++i){
    scanf("%d", &p[i]);
  }

  for(int i = 1; i <= n; ++i){
    scanf("%d", &a[i]);
  }

  for(int i = 1; i <= n; ++i){
    int k = p[i];
    d[i] = 1 - d[k];
    if(d[i]){
      a[k] = min(a[k], a[i]);
    }
    else{
      a[i] = INT_MAX;
    }
  }

  for(int i = 2; i <= n; ++i){
    if(a[i] == INT_MAX){
      a[i] = a[p[i]];
    }
  }

  ll ans = 0;
  for(int i = 1; i <= n; ++i){
    if(a[i] < a[p[i]]){
      ans = INT_MIN;
    }
  }

  ans += a[1];
  for(int i = 2; ans >= 0 && i <= n; ++i){
    ans += (a[i] - a[p[i]]);
  }

  ans = (ans < 0) ?  -1 : ans;
  printf("%lld\n", ans);

  return 0;
}