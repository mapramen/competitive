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
#define N 300001
#define M (1 << 20)

int a[N];

//----------------------------------------- Segment Tree -----------------------------------------//
ll oddMin[M], oddMax[M], evenMin[M], evenMax[M];

void Combine(int k){
  int k1 = 2 * k + 1, k2 = 2 * k + 2;

  oddMin[k] = min(oddMin[k1] - evenMax[k2], evenMin[k1] + oddMin[k2]);
  oddMax[k] = max(oddMax[k1] - evenMin[k2], evenMax[k1] + oddMax[k2]);
  evenMin[k] = min(oddMin[k1] - oddMax[k2], evenMin[k1] + evenMin[k2]);
  evenMax[k] = max(oddMax[k1] - oddMin[k2], evenMax[k1] + evenMax[k2]);
}

void ResetLeaf(int k, int i){
  oddMin[k] = a[i], oddMax[k] = a[i];
  evenMin[k] = 0, evenMax[k] = 0;
}

void BuildSegmentTree(int k, int l, int r){
  if(l == r){
    ResetLeaf(k, l);
  }
  else{
    BuildSegmentTree(2 * k + 1, l, (l + r) / 2);
    BuildSegmentTree(2 * k + 2, (l + r) / 2 + 1, r);
    Combine(k);
  }
}

void Update(int k, int l, int r, int i){
  if(i < l || r < i){
    return;
  }

  if(l == i && r == i){
    ResetLeaf(k, i);
    return;
  }

  Update(2 * k + 1, l, (l + r) / 2, i);
  Update(2 * k + 2, (l + r) / 2 + 1, r, i);
  Combine(k);
}
//-------------------------------------- Segment Tree Ends --------------------------------------//

void PrintAns(){
  printf("%lld\n", max(oddMax[0], evenMax[0]));
}

void Solve(){
  int n, q;

  scanf("%d%d", &n, &q);
  for(int i = 1; i <= n; ++i){
    scanf("%d", &a[i]);
  }

  BuildSegmentTree(0, 1, n);
  PrintAns();

  while(q--){
    int l, r;
    scanf("%d%d", &l, &r);

    if(l != r && a[l] != a[r]){
      swap(a[l], a[r]);
      Update(0, 1, n, l);
      Update(0, 1, n, r);
    }

    PrintAns();
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