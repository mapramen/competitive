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
#include <climits>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 200001
#define M (1 << 19)
#define K 32
#define B 5

int n, b[K][N], multipliers[K][B], a[B], allOnes;

//----------------------------------------- Segment Tree -----------------------------------------//
int T[K][M];

void BuildSegmentTree(int T[], int a[], int k, int l, int r){
  if(l == r){
    T[k] = a[l];
  }
  else{
    BuildSegmentTree(T, a, 2 * k + 1, l, (l + r) / 2);
    BuildSegmentTree(T, a, 2 * k + 2, (l + r) / 2 + 1, r);
    T[k] = max(T[2 * k + 1], T[2 * k + 2]);
  }
}

void Update(int T[], int k, int l, int r, int i, int x){
  if(i < l || r < i){
    return ;
  }
  else{
    if(i == l && i == r){
      T[k] = x;
    }
    else{
      Update(T, 2 * k + 1, l, (l + r) / 2, i, x);
      Update(T, 2 * k + 2, (l + r) / 2 + 1, r, i, x);
      T[k] = max(T[2 * k + 1], T[2 * k + 2]);
    }
  }
}

int Query(int T[], int k, int l, int r, int ql, int qr){
  if(qr < ql || qr < l || r < ql){
    return INT_MIN;
  }
  else{
    if(ql <= l && r <= qr){
      return T[k];
    }
    else{
      return max(Query(T, 2 * k + 1, l, (l + r) / 2, ql, qr), Query(T, 2 * k + 2, (l + r) / 2 + 1, r, ql, qr));
    }
  }
}
//-------------------------------------- Segment Tree Ends --------------------------------------//

void InputCoordinates(int k){
  for(int i = 0; i < k; ++i){
    scanf("%d", &a[i]);
  }
}

int GetMaskedNumber(int k, int mask){
  int x = 0;
  for(int j = 0; j < k; ++j){
    x += (multipliers[mask][j] * a[j]);
  }
  return x;
}

void PreProcess(int k){
  allOnes = (1 << k) - 1;
  for(int mask = 0; mask <= allOnes; ++mask){
    for(int i = 0; i < k; ++i){
      int j = (mask & (1 << i)) > 0;
      multipliers[mask][i] = j ? 1 : -1;
    }
  }

  for(int i = 1; i <= n; ++i){
    InputCoordinates(k);
    for(int mask = 0; mask <= allOnes; ++mask){
      b[mask][i] = GetMaskedNumber(k, mask);
    }
  }

  for(int mask = 0; mask <= allOnes; ++mask){
    BuildSegmentTree(T[mask], b[mask], 0, 1, n);
  }
}

void Update(int k, int i){
  for(int mask = 0; mask <= allOnes; ++mask){
    Update(T[mask], 0, 1, n, i, GetMaskedNumber(k, mask));
  }
}

void InputCoordinatesAndUpdate(int k, int i){
  InputCoordinates(k);
  Update(k, i);
}

int Query(int l, int r){
  int ans = 0;
  for(int mask = 0; mask <= allOnes; ++mask){
    int xorMask = (allOnes ^ mask);
    if(mask > xorMask){
      continue;
    }
    ans = max(ans, Query(T[mask], 0, 1, n, l, r) + Query(T[xorMask], 0, 1, n, l, r));
  }
  return ans;
}

int main(){
  int k;
  scanf("%d%d", &n, &k);

  PreProcess(k);

  int q;
  scanf("%d", &q);
  while(q--){
    int t;
    scanf("%d", &t);
    if(t == 1){
      int i;
      scanf("%d", &i);
      InputCoordinatesAndUpdate(k, i);
    }
    else{
      int l, r;
      scanf("%d%d", &l, &r);
      printf("%d\n", Query(l, r));
    }
  }

  return 0;
}