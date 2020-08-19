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
#define tiii tuple<int,int,int>
#define N 1000001
#define B 22
#define M (1 << B)
#define MOD 1000000007

int L[N], H[N], W[N];
vector<int> C;

void ReadArrayInput(int A[], int n, int k){
  for(int i = 1; i <= k; ++i){
    scanf("%d", &A[i]);
  }

  ll a, b, c, d;
  scanf("%lld%lld%lld%lld", &a, &b, &c, &d);

  for(int i = k + 1; i <= n; ++i){
    A[i] = 1 + (a * A[i - 2] + b * A[i - 1] + c) % d;
  }
}

void ReadLengths(int n, int k){
  ReadArrayInput(L, n, k);
}

void ReadHeights(int n, int k){
  ReadArrayInput(H, n, k);
}

void ReadWidths(int n, int k){
  ReadArrayInput(W, n, k);
}

int ReadInputs(){
  int n, k;
  scanf("%d%d", &n, &k);
  
  ReadLengths(n, k);
  ReadWidths(n, k);
  ReadHeights(n, k);

  return n;
}

int GetCompressedValue(int x){
  return lower_bound(C.begin(), C.end(), x) - C.begin();
}

int CompressCoordinates(int n){
  C.clear();
  for(int i = 1; i <= n; ++i){
    C.push_back(L[i]);
    C.push_back(L[i] + W[i]);
  }
  C.push_back(0);

  sort(C.begin(), C.end());
  C.erase(unique(C.begin(), C.end()), C.end());

  C.push_back(INT_MAX);
  C.push_back(INT_MAX);
  C.push_back(INT_MAX);

  return C.size() - 2;
}

//----------------------------------------- Segment Tree -----------------------------------------//
int a[M], xPerimeter[M], yPerimeter[M], yLeftEnd[M], yRightEnd[M], yMin[M], yMax[M], lazyValue[M];
bool isEntireSegmentActive[M];

void BuildSegmentTree(int k, int l, int r){
  if(l != r){
    BuildSegmentTree(2 * k + 1, l, (l + r) / 2);
    BuildSegmentTree(2 * k + 2, (l + r) / 2 + 1, r);
  }
  a[k] = C[r + 1] - C[l];
  xPerimeter[k] = 0;
  yPerimeter[k] = 0;
  yMin[k] = 0;
  yMax[k] = 0;
  yLeftEnd[k] = 0;
  yRightEnd[k] = 0;
  lazyValue[k] = 0;
  isEntireSegmentActive[k] = false;
}

void UpdateNode(int k, int y){
  yMin[k] = y, yMax[k] = y;
  yLeftEnd[k] = y, yRightEnd[k] = y;
  
  lazyValue[k] = y;
  
  yPerimeter[k] = 0;

  if(!isEntireSegmentActive[k]){
    isEntireSegmentActive[k] = true;
    xPerimeter[k] = a[k];
  }
}

void Combine(int k){
  int k1 = 2 * k + 1, k2 = 2 * k + 2;

  yMin[k] = min(yMin[k1], yMin[k2]);
  yMax[k] = max(yMax[k1], yMax[k2]);

  yLeftEnd[k] = yLeftEnd[k1];
  yRightEnd[k] = yRightEnd[k2];

  xPerimeter[k] = (xPerimeter[k1] + xPerimeter[k2]) % MOD;
  yPerimeter[k] = (yPerimeter[k1] + yPerimeter[k2]) % MOD;
  yPerimeter[k] = (yPerimeter[k] + max(0, yLeftEnd[k2] - yRightEnd[k1])) % MOD;
}

void LazyUpdateChildren(int k){
  if(lazyValue[k] == 0){
    return;
  }

  UpdateNode(2 * k + 1, lazyValue[k]);
  UpdateNode(2 * k + 2, lazyValue[k]);
  lazyValue[k] = 0;
}

void Update(int k, int l, int r, int ql, int qr, int y){
  if(qr < l || r < ql || y <= yMin[k]){
    return;
  }

  if(ql <= l && r <= qr && (yMin[k] == yMax[k] && yMax[k] <= y)){
    UpdateNode(k, y);
    return;
  }

  LazyUpdateChildren(k);
  Update(2 * k + 1, l, (l + r) / 2, ql, qr, y);
  Update(2 * k + 2, (l + r) / 2 + 1, r, ql, qr, y);
  Combine(k);
}
//-------------------------------------- Segment Tree Ends --------------------------------------//

void InitialisePerimeter(int m){
  BuildSegmentTree(0, 0, m);
}

int AddRectangle(int m, int x1, int x2, int y){
  Update(0, 0, m, GetCompressedValue(x1), GetCompressedValue(x2) - 1, y);
  int semiPerimeter = (xPerimeter[0] + yPerimeter[0]) % MOD;
  return (2 * semiPerimeter) % MOD;
}

int Solve(){
  int n = ReadInputs();
  int m = CompressCoordinates(n);

  InitialisePerimeter(m);

  int ans = 1;
  for(int i = 1; i <= n; ++i){
    ans = (1ll * ans * AddRectangle(m, L[i], L[i] + W[i], H[i])) % MOD;
  }

  return ans;
}

int main(){
  int t;
  scanf("%d", &t);
  for(int k = 1; k <= t; ++k){
    printf("Case #%d: %d\n", k, Solve());
  }
  return 0;
}