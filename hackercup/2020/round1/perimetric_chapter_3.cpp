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
#define B 23
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
  int w;
  scanf("%d", &w);

  for(int i = 1; i <= n; ++i){
    W[i] = w;
  }
}

int ReadInputs(){
  int n, k;
  scanf("%d%d", &n, &k);
  
  ReadWidths(n, k);
  ReadLengths(n, k);
  ReadHeights(n, k);

  return n;
}

int GetCompressedValue(int x){
  return lower_bound(C.begin(), C.end(), x) - C.begin();
}

int GetOriginalValue(int i){
  return C[i];
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

  return C.size() - 1;
}

//----------------------------------------- Segment Tree -----------------------------------------//
int T[M];

void BuildSegmentTree(int k, int l, int r){
  if(l != r){
    BuildSegmentTree(2 * k + 1, l, (l + r) / 2);
    BuildSegmentTree(2 * k + 2, (l + r) / 2 + 1, r);
  }
  T[k] = 0;
}

void Update(int k, int l, int r, int ql, int qr, int x){
  if(qr < l || r < ql){
    return;
  }

  if(ql <= l && r <= qr){
    T[k] = max(T[k], x);
    return;
  }

  Update(2 * k + 1, l, (l + r) / 2, ql, qr, x);
  Update(2 * k + 2, (l + r) / 2 + 1, r, ql, qr, x);
}

int Query(int k, int l, int r, int i){
  if(r < i || i < l){
    return 0;
  }

  if(l == i && r == i){
    return T[k];
  }

  return max(T[k], max(Query(2 * k + 1, l, (l + r) / 2, i), Query(2 * k + 2, (l + r) / 2 + 1, r, i)));
}
//-------------------------------------- Segment Tree Ends --------------------------------------//

map<int,int> xSegments;

void InitialisePerimeter(int m){
  xSegments.clear();
  xSegments[0] = 0;
  xSegments[INT_MAX] = INT_MAX;

  BuildSegmentTree(0, 1, m);
}

int AddXSegment(int l, int r){
  auto it = prev(xSegments.upper_bound(l));

  if(it->second < l){
    ++it;
  }

  int ans = 0;
  vector<int> v;

  for( ; it->first <= r; ++it){
    l = min(l, it->first);
    r = max(r, it->second);
    ans += (it->second - it->first);
    v.push_back(it->first);
  }

  for(int x: v){
    xSegments.erase(x);
  }
  v.clear();

  ans = (r - l) - ans;
  xSegments[l] = r;

  printf("AddXSegment ans = %d\n", ans);

  return ans;
}

int AddYSegment(int m, int x, int y){
  printf("AddYSegment x = %d y = %d ans = %d\n", x, y, Query(0, 1, m, GetCompressedValue(x)));
  return max(0, y - Query(0, 1, m, GetCompressedValue(x)));
}

int AddRectangle(int m, int x1, int x2, int y){
  int ans = (2ll * AddXSegment(x1, x2) + AddYSegment(m, x1, y) + AddYSegment(m, x2, y)) % MOD;

  Update(0, 1, m, GetCompressedValue(x1), GetCompressedValue(x2), y);

  return ans;
}

int Solve(){
  int n = ReadInputs();
  int m = CompressCoordinates(n);

  InitialisePerimeter(m);

  int ans = 1, perimeter = 0;
  for(int i = 1; i <= n; ++i){
    perimeter += AddRectangle(m, L[i], L[i] + W[i], H[i]);
    perimeter %= MOD;
    printf("i = %d perimeter = %d\n", i, perimeter);
    ans = (1ll * ans * perimeter) % MOD;
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