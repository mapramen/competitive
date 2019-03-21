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

#define pii pair< int, int>
#define pll pair< ll, ll>
#define N 100001

int a[N], c[N];
priority_queue< pii, vector< pii >, greater< pii > > Q;

ll Cost(int t, int &d){
  int x = min(a[t], d);
  d -= x;
  a[t] -= x;
  return 1ll * x * c[t];
}

void RefreshQueue(){
  while(!Q.empty() && a[Q.top().second] == 0){
    Q.pop();
  }
}

int main(){
  int n, m;

  scanf("%d%d", &n, &m);

  for(int i = 1; i <= n; ++i){
    scanf("%d", &a[i]);
  }

  for(int i = 1; i <= n; ++i){
    scanf("%d", &c[i]);
  }

  for(int i = 1; i <= n; ++i){
    Q.push(make_pair(c[i], i));
  }

  while(m--){
    int t, d;

    scanf("%d%d", &t, &d);

    ll ans = Cost(t, d);

    for(RefreshQueue(); d > 0 && !Q.empty(); RefreshQueue()){
      t = Q.top().second;
      ans += Cost(t, d);
    }

    if(d){
      ans = 0;
    }

    printf("%lld\n", ans);
  }

  return 0;
}