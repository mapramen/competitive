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
#define N 1000002

ll a[N], B[N], inf = 1E18;
deque<int> Q;

void SlidingMinimumWindow(int n, int k){
  a[1] = a[n] = 0;
  B[n + 1] = 0;
  
  Q.push_back(n + 1);

  for(int i = n; i > 0; --i){
    for( ; !Q.empty() && Q.front() - i > k; Q.pop_front());
    B[i] = min(inf, a[i] + B[Q.front()]);
    for( ; !Q.empty() && B[Q.back()] >= B[i]; Q.pop_back());
    Q.push_back(i);
  }

  for( ; !Q.empty(); Q.pop_back());
}

ll Solve(){
  int n, m;
  scanf("%d%d", &n, &m);

  for(int i = 1; i <= n; ++i){
    ll x;
    scanf("%lld", &x);
    if(x == 0){
      x = inf;
    }
    a[i] = x;
  }

  SlidingMinimumWindow(n, m);

  return B[1] == inf ? -1 : B[1];
}

int main(){
  int t;
  scanf("%d", &t);
  for(int k = 1; k <= t; ++k){
    printf("Case #%d: %lld\n", k, Solve());
  }
  return 0;
}