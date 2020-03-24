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
#define N 100001
#define B 18
#define M (1 << B)

ll a[N];
char s[2];

//----------------------------------------- Segment Tree -----------------------------------------//
ll lazyValue[M], minValue[M], maxValue[M];

inline void Combine(int k){
  const int k1 = 2 * k + 1, k2 = 2 * k + 2;
  minValue[k] = min(minValue[k1], minValue[k2]);
  maxValue[k] = max(maxValue[k1], maxValue[k2]);
}

void InitialiseSegmentTree(int k, int l, int r){
  if(l == r){
    minValue[k] = a[l], maxValue[k] = a[l];
  }
  else{
    InitialiseSegmentTree(2 * k + 1, l, (l + r) / 2);
    InitialiseSegmentTree(2 * k + 2, (l + r) / 2 + 1, r);
    Combine(k);
  }
  lazyValue[k] = 0;
}

inline void UpdateNode(int k, ll x){
  lazyValue[k] += x;
  minValue[k] += x;
  maxValue[k] += x;
}

inline void LazyUpdateChildren(int k){
  if(lazyValue[k] == 0){
    return;
  }

  UpdateNode(2 * k + 1, lazyValue[k]);
  UpdateNode(2 * k + 2, lazyValue[k]);
  lazyValue[k] = 0;
}

void Update(int k, int l, int r, int ql, int qr, int x){
  if(r < ql || qr < l || r < l){
    return;
  }

  if(ql <= l && r <= qr){
    UpdateNode(k, x);
    return;
  }

  LazyUpdateChildren(k);
  Update(2 * k + 1, l, (l + r) / 2, ql, qr, x);
  Update(2 * k + 2, (l + r) / 2 + 1, r, ql, qr, x);
  Combine(k);
}

ll QueryMin(int k, int l, int r, int ql, int qr){
  if(r < ql || qr < l || r < l){
    return LLONG_MAX;
  }

  if(ql <= l && r <= qr){
    return minValue[k];
  }

  LazyUpdateChildren(k);
  ll ans = min(QueryMin(2 * k + 1, l, (l + r) / 2, ql, qr), QueryMin(2 * k + 2, (l + r) / 2 + 1, r, ql, qr));
  Combine(k);

  return ans;
}

ll QueryMax(int k, int l, int r, int ql, int qr){
  if(r < ql || qr < l || r < l){
    return LLONG_MIN;
  }

  if(ql <= l && r <= qr){
    return maxValue[k];
  }

  LazyUpdateChildren(k);
  ll ans = max(QueryMax(2 * k + 1, l, (l + r) / 2, ql, qr), QueryMax(2 * k + 2, (l + r) / 2 + 1, r, ql, qr));
  Combine(k);

  return ans;
}
//-------------------------------------- Segment Tree Ends ---------------------------------------//

void PreProcess(int n){
  for(int i = 1; i <= n; ++i){
    a[i] += a[i - 1];
  }
  InitialiseSegmentTree(0, 0, n);

  for(int i = n; i > 0; --i){
    a[i] -= a[i - 1];
  }
}

void Update(int n, int i, int x){
  Update(0, 0, n, i, n, x - a[i]);
  a[i] = x;
}

ll Query(int n, int l, int r){
  return QueryMax(0, 0, n, r, n) - QueryMin(0, 0, n, 0, l - 1);
}

void Solve(){
  int n, q;

  scanf("%d%d", &n, &q);
  for(int i = 1; i <= n; ++i){
    scanf("%lld", &a[i]);
  }

  PreProcess(n);

  while(q--){
    scanf("%s", s);

    if(s[0] == 'Q'){
      int l, r;
      scanf("%d%d", &l, &r);
      printf("%lld\n", Query(n, l, r));
    }
    else{
      int i, x;
      scanf("%d%d", &i, &x);
      Update(n, i, x);
    }
  }
}

int main(){
  int t;
  scanf("%d", &t);
  while(t--){
    Solve();
  }
  return 0;
}