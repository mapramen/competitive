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
#define N 100000
#define M (1 << 19)
#define K 11

int startIndex = N, endIndex = N, m = 0, temp[K];
string qs;

//----------------------------------------- Segment Tree -----------------------------------------//
int T[M][K], lazyValue[M], xorValue[M];

void BuildSegmentTree(int k, int l, int r){
  T[k][0] = (r - l + 1);
  if(l != r){
    BuildSegmentTree(2 * k + 1, l, (l + r) / 2);
    BuildSegmentTree(2 * k + 2, (l + r) / 2 + 1, r);
  }
}

void UpdateNode(int k, int x){
  x %= m;
  x = (x + m) % m;

  if(x == 0){
    return;
  }

  lazyValue[k] = (lazyValue[k] + x) % m;
  for(int i = 0; i < m; ++i){
    temp[i] = 0;
  }

  for(int i = 0; i < m; ++i){
    temp[(i + x) % m] = T[k][i];
  }

  for(int i = 0; i < m; ++i){
    T[k][i] = temp[i];
  }

  xorValue[k] = 0;
  for(int i = 1; i < m; ++i){
    if(T[k][i] % 2){
      xorValue[k] ^= i;
    }
  }
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
  int k1 = 2 * k + 1, k2 = 2 * k + 2;
  for(int i = 0; i < m; ++i){
    T[k][i] = T[k1][i] + T[k2][i];
  }
  xorValue[k] = xorValue[k1] ^ xorValue[k2];
}

void RangeUpdate(int k, int l, int r, int ql, int qr, int x){
  if(qr < l || r < ql || r < l){
    return;
  }

  if(ql <= l && r <= qr){
    UpdateNode(k, x);
    return;
  }

  LazyUpdateChildren(k);
  RangeUpdate(2 * k + 1, l, (l + r) / 2, ql, qr, x);
  RangeUpdate(2 * k + 2, (l + r) / 2 + 1, r, ql, qr, x);
  Combine(k);
}

void PointUpdate(int k, int l, int r, int i, int x){
  if(r < l || i < l || r < i){
    return;
  }

  if(l == i && r == i){
    UpdateNode(k, x - lazyValue[k]);
    return;
  }

  LazyUpdateChildren(k);
  PointUpdate(2 * k + 1, l, (l + r) / 2, i, x);
  PointUpdate(2 * k + 2, (l + r) / 2 + 1, r, i, x);
  Combine(k);
}

int NoOfPilesQuery(int k, int l, int r, int ql, int qr){
  if(r < l || r < ql || qr < l){
    return 0;
  }

  if(ql <= l && r <= qr){
    return (r - l + 1) - T[k][0];
  }

  LazyUpdateChildren(k);
  int ans = NoOfPilesQuery(2 * k + 1, l, (l + r) / 2, ql, qr) + NoOfPilesQuery(2 * k + 2, (l + r) / 2 + 1, r, ql, qr);
  Combine(k);

  return ans;
}

int GameQuery(int k, int l, int r, int ql, int qr){
  if(r < l || r < ql || qr < l){
    return 0;
  }

  if(ql <= l && r <= qr){
    return xorValue[k];
  }

  LazyUpdateChildren(k);
  int ans = GameQuery(2 * k + 1, l, (l + r) / 2, ql, qr) ^ GameQuery(2 * k + 2, (l + r) / 2 + 1, r, ql, qr);
  Combine(k);
  
  return ans;
}

void PrintTree(int k, int l, int r, int ql, int qr){
  if(r < l || r < ql || qr < l){
    return ;
  }

  if(l == r){
    printf("i = %d val = %d t0 = %d xor = %d\n", l, lazyValue[k], T[k][0], xorValue[k]);
    return;
  }

  LazyUpdateChildren(k);
  PrintTree(2 * k + 1, l, (l + r) / 2, ql, qr);
  PrintTree(2 * k + 2, (l + r) / 2 + 1, r, ql, qr);
  Combine(k);
}
//-------------------------------------- Segment Tree Ends --------------------------------------//

int main(){
  int q;
  const int L = 0, R = 2 * N;

  scanf("%d%d", &q, &m);
  ++m;

  BuildSegmentTree(0, L, R);

  while(q--){
    cin >> qs;

    if(qs == "AL"){
      int x;
      scanf("%d", &x);
      PointUpdate(0, L, R, --startIndex, x);
    }
    else if(qs == "AR"){
      int x;
      scanf("%d", &x);
      PointUpdate(0, L, R, endIndex++, x);
    }
    else if(qs == "UR"){
      int l, r, x;
      scanf("%d%d%d", &l, &r, &x);
      RangeUpdate(0, L, R, startIndex + l - 1, startIndex + r - 1, x);
    }
    else if(qs == "UP"){
      int i, x;
      scanf("%d%d", &i, &x);
      PointUpdate(0, L, R, startIndex + i - 1, x);
    }
    else if(qs == "Q1"){
      int l, r;
      scanf("%d%d", &l, &r);
      printf("%d\n", NoOfPilesQuery(0, L, R, startIndex + l - 1, startIndex + r - 1));
    }
    else{
      int l, r;
      scanf("%d%d", &l, &r);
      printf("%s\n", GameQuery(0, L, R, startIndex + l - 1, startIndex + r - 1) == 0 ? "Jerry" : "Tom");
    }
  }

  return 0;
}