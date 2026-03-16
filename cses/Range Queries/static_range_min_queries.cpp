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
int T[M];

void BuildSegmentTree(int k, int l, int r){
  if(l == r){
    T[k] = a[l];
  }
  else{
    BuildSegmentTree(2 * k + 1, l, (l + r) / 2);
    BuildSegmentTree(2 * k + 2, (l + r) / 2 + 1, r);
    T[k] = min(T[2 * k + 1], T[2 * k + 2]);
  }
}

int Query(int k, int l, int r, int ql, int qr){
  if(qr < l || r < ql){
    return INT_MAX;
  }

  if(ql <= l && r <= qr){
    return T[k];
  }

  int ans1 = Query(2 * k + 1, l, (l + r) / 2, ql, qr);
  int ans2 = Query(2 * k + 2, (l + r) / 2 + 1, r, ql, qr);

  return min(ans1, ans2);
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
    int l, r;
    scanf("%d%d", &l, &r);
    printf("%d\n", Query(0, 1, n, l, r));
  }
  
  return 0;
}