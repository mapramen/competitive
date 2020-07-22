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
#define MOD 998244353 

char s[N];

//----------------------------------------- Segment Tree -----------------------------------------//
int startDigit[M], endDigit[M], T[M][2][2];

int Cost(int x){
  return x + 1;
}

int Cost(int x, int y){
  if(x != 1){
    return 0;
  }
  return 9 - y;
}

void MatrixMultiplication(int C[2][2], int A[2][2], int B[2][2], int mul){
  for(int i = 0; i < 2; ++i){
    for(int j = 0; j < 2; ++j){
      C[i][j] = (1ll * A[i][0] * B[0][j] + 1ll * mul * ((1ll * A[i][1] * B[1][j]) % MOD)) % MOD;
    }
  }
}

void Combine(int k){
  int k1 = 2 * k + 1, k2 = 2 * k + 2;
  startDigit[k] = startDigit[k1], endDigit[k] = endDigit[k2];
  MatrixMultiplication(T[k], T[k1], T[k2], Cost(endDigit[k1], startDigit[k2]));
}

void UpdateLeaf(int k, int x){
  T[k][0][0] = Cost(x);
  startDigit[k] = x, endDigit[k] = x;
}

void BuildSegmentTree(int k, int l, int r){
  if(l == r){
    T[k][0][1] = 1, T[k][1][0] = 1;
    T[k][1][1] = 0;
    UpdateLeaf(k, s[l - 1] - '0');
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
    UpdateLeaf(k, x);
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
  scanf("%s", s);

  BuildSegmentTree(0, 1, n);

  while(q--){
    int i, x;
    scanf("%d%d", &i, &x);
    Update(0, 1, n, i, x);
    printf("%d\n", T[0][0][0]);
  }

  return 0;
}