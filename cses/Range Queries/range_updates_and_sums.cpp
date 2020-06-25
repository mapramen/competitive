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
#define B 19
#define M (1 << B)

int a[N];

//----------------------------------------- Segment Tree -----------------------------------------//
int length[M], lazyMultiplier[M];
ll sum[M], lazySum[M];

void Combine(int k){
  sum[k] = sum[2 * k + 1] + sum[2 * k + 2];
}

void UpdateNode(int k, int m, ll c){
  if(m == 1 && c == 0){
    return;
  }

  sum[k] = m * sum[k] + c * length[k];
  lazySum[k] = m * lazySum[k] + c;
  lazyMultiplier[k] *= m;
}

void BuildSegmentTree(int k, int l, int r){
  if(l == r){
    sum[k] = a[l];
  }
  else{
    BuildSegmentTree(2 * k + 1, l, (l + r) / 2);
    BuildSegmentTree(2 * k + 2, (l + r) / 2 + 1, r);
    Combine(k);
  }
  lazyMultiplier[k] = 1;
  lazySum[k] = 0;
  length[k] = r - l + 1;
}

void LazyUpdateChildren(int k){
  UpdateNode(2 * k + 1, lazyMultiplier[k], lazySum[k]);
  UpdateNode(2 * k + 2, lazyMultiplier[k], lazySum[k]);
  lazyMultiplier[k] = 1, lazySum[k] = 0;
}

void Update(int k, int l, int r, int ql, int qr, int m, int c){
  if(r < l || qr < l || r < ql){
    return;
  }

  if(ql <= l && r <= qr){
    UpdateNode(k, m, c);
    return;
  }

  LazyUpdateChildren(k);
  Update(2 * k + 1, l, (l + r) / 2, ql, qr, m, c);
  Update(2 * k + 2, (l + r) / 2 + 1, r, ql, qr, m, c);
  Combine(k);
}

ll Query(int k, int l, int r, int ql, int qr){
  if(r < l || qr < l || r < ql){
    return 0;
  }

  if(ql <= l && r <= qr){
    return sum[k];
  }

  LazyUpdateChildren(k);
  ll ans = Query(2 * k + 1, l, (l + r) / 2, ql, qr) + Query(2 * k + 2, (l + r) / 2 + 1, r, ql, qr);
  Combine(k);

  return ans;
}
//-------------------------------------- Segment Tree Ends --------------------------------------//

int main(){
  int n, q;

  scanf("%d%d", &n, &q);

  for(int i = 1; i <= n; ++i){
    scanf("%d", &a[i]);
  }

  BuildSegmentTree(0, 1, n);

  while(q--){
    int k, l, r;

    scanf("%d%d%d", &k, &l, &r);

    if(k < 3){
      int x;
      scanf("%d", &x);
      Update(0, 1, n, l, r, k == 1, x);
    }
    else{
      printf("%lld\n", Query(0, 1, n, l, r));
    }
  }
  
  return 0;
}