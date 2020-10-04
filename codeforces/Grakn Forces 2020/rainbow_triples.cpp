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
#define N 500001
#define M (1 << 20)

int a[N], last[N];

//----------------------------------------- Segment Tree -----------------------------------------//
int T[M], lazyValue[M];

void BuildSegmentTree(int k, int l, int r){
  if(l != r){
    BuildSegmentTree(2 * k + 1, l, (l + r) / 2);
    BuildSegmentTree(2 * k + 2, (l + r) / 2 + 1, r);
  }
  T[k] = 0;
  lazyValue[k] = 0;
}

void UpdateNode(int k, int x){
  if(x == 0){
    return;
  }
  T[k] += x;
  lazyValue[k] += x;
}

void LazyUpdateChildren(int k){
  if(lazyValue[k] == 0){
    return;
  }
  UpdateNode(2 * k + 1, lazyValue[k]);
  UpdateNode(2 * k + 2, lazyValue[k]);
  lazyValue[k] = 0;
}

void Combine(int k){
  T[k] = min(T[2 * k + 1], T[2 * k + 2]);
}

void Update(int k, int l, int r, int ql, int qr, int x){
  if(r < l || qr < l || r < ql){
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

int Query(int k, int l, int r, int ql, int qr){
  if(r < l || qr < l || r < ql){
    return INT_MAX;
  }

  if(ql <= l && r <= qr){
    return T[k];
  }

  LazyUpdateChildren(k);
  int ans1 = Query(2 * k + 1, l, (l + r) / 2, ql, qr);
  int ans2 = Query(2 * k + 2, (l + r) / 2 + 1, r, ql, qr);
  Combine(k);

  return min(ans1, ans2);
}
//-------------------------------------- Segment Tree Ends --------------------------------------//

int Solve(){
  int n;
  scanf("%d", &n);

  for(int i = 1; i <= n; ++i){
    scanf("%d", &a[i]);
  }

  BuildSegmentTree(0, 1, n);

  int zero = 0;
  for(int i = 1; i <= n; ++i){
    Update(0, 1, n, i, i, zero);
    zero += (a[i] == 0);
  }

  for(int i = 0; i <= n; ++i){
    last[i] = 0;
  }

  int ans = zero / 2;
  for(int i = 1; i <= n; ++i){
    zero -= (a[i] == 0);

    if(a[i] != 0){
      int k = a[i];
      Update(0, 1, n, last[k] + 1, i, 1);
      last[k] = i;
    }
    
    ans = min(ans, Query(0, 1, n, 1, i) + zero);
  }

  return ans;
}

int main(){
  int t;
  scanf("%d", &t);
  while(t--){
    printf("%d\n", Solve());
  }
  return 0;
}