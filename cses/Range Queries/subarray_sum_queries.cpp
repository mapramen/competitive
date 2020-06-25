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
ll sum[M], prefixAns[M], suffixAns[M], ans[M];

void Combine(int k){
  int k1 = 2 * k + 1, k2 = 2 * k + 2;
  sum[k] = sum[k1] + sum[k2];
  prefixAns[k] = max(prefixAns[k1], sum[k1] + prefixAns[k2]);
  suffixAns[k] = max(suffixAns[k2], suffixAns[k1] + sum[k2]);
  ans[k] = max(suffixAns[k1] + prefixAns[k2], max(ans[k1], ans[k2]));
}

void Update(int k, int x){
  sum[k] = x, prefixAns[k] = x, suffixAns[k] = x, ans[k] = x;
}

void BuildSegmentTree(int k, int l, int r){
  if(l == r){
    Update(k, a[l]);
  }
  else{
    BuildSegmentTree(2 * k + 1, l, (l + r) / 2);
    BuildSegmentTree(2 * k + 2, (l + r) / 2 + 1, r);
    Combine(k);
  }
}

void Update(int k, int l, int r, int i, int x){
  if(i < l || r < i){
    return;
  }

  if(l == i && r == i){
    Update(k, x);
    return;
  }

  Update(2 * k + 1, l, (l + r) / 2, i, x);
  Update(2 * k + 2, (l + r) / 2 + 1, r, i, x);
  Combine(k);
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
    int i, x;
    scanf("%d%d", &i, &x);
    Update(0, 1, n, i, x);
    printf("%lld\n", ans[0]);
  }
  
  return 0;
}