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
#define N 100001
#define B 18
#define M (1 << B)
#define K 10

int a[N], primeFactors[K], m = 0, mod, phi, updateVector[K];

void AddPrimeFactor(int i){
  if(i == 1){
    return;
  }
  if(i < N){
    primeFactors[++m] = i;
  }
  phi /= i;
  phi *= (i - 1);
}

void PreProcess(){
  int n = mod;
  phi = mod;
  for(int i = 2; i * i <= n; ++i){
    if(n % i != 0){
      continue;
    }
    AddPrimeFactor(i);
    for( ; n % i == 0; n /= i);
  }
  AddPrimeFactor(n);
}

int ModularExponentation(int a, int n){
  int ans = 1 % mod;
  for( ; n; n /= 2, a = (1ll * a * a) % mod){
    if(n % 2){
      ans = (1ll * a * ans) % mod;
    }
  }
  return ans;
}

int ModularInverse(int a){
  return ModularExponentation(a, phi - 1);
}

void FillPrimeFactorVector(int n, int x, int v[]){
  for(int i = 1; i <= m; ++i){
    int p = primeFactors[i];
    v[i] = 0;
    for( ; n % p == 0; v[i] += x, n /= p);
  }
  v[0] = (x == 1) ? n : ModularInverse(n);
}

int GetNumberFromPrimeFactorVector(int v[]){
  int ans = v[0];
  for(int i = 1; i <= m; ++i){
    ans = (1ll * ans * ModularExponentation(primeFactors[i], v[i])) % mod;
  }
  return ans;
}

//----------------------------------------- Segment Tree -----------------------------------------//
int sum[M], lazyMultiplier[M], lazyValue[M][K];

void ResetLazy(int k){
  for(int i = 1; i <= m; ++i){
    lazyValue[k][i] = 0;
  }
  lazyValue[k][0] = 1;
  lazyMultiplier[k] = 1;
}

void Combine(int k){
  sum[k] = (sum[2 * k + 1] + sum[2 * k + 2]) % mod;
}

void BuildSegmentTree(int k, int l, int r){
  ResetLazy(k);

  if(l == r){
    FillPrimeFactorVector(a[l], 1, lazyValue[k]);
    sum[k] = a[l] % mod;
  }
  else{
    BuildSegmentTree(2 * k + 1, l, (l + r) / 2);
    BuildSegmentTree(2 * k + 2, (l + r) / 2 + 1, r);
    Combine(k);
  }
}

void UpdateNode(int k, int x, int v[]){
  for(int i = 1; i <= m; ++i){
    lazyValue[k][i] += v[i];
  }
  lazyValue[k][0] = (1ll * lazyValue[k][0] * v[0]) % mod;
  lazyMultiplier[k] = (1ll * x * lazyMultiplier[k]) % mod;
  sum[k] = (1ll * x * sum[k]) % mod;
}

void LazyUpdateChildren(int k){
  if(lazyMultiplier[k] == 1){
    return ;
  }

  UpdateNode(2 * k + 1, lazyMultiplier[k], lazyValue[k]);
  UpdateNode(2 * k + 2, lazyMultiplier[k], lazyValue[k]);

  ResetLazy(k);
}

void Update(int k, int l, int r, int ql, int qr, int x, int v[], bool isDivide){
  if(qr < l || r < ql){
    return ;
  }

  if(ql <= l && r <= qr){
    UpdateNode(k, x, v);
    if(isDivide){
      sum[k] = GetNumberFromPrimeFactorVector(lazyValue[k]);
    }
    return ;
  }

  LazyUpdateChildren(k);
  Update(2 * k + 1, l, (l + r) / 2, ql, qr, x, v, isDivide);
  Update(2 * k + 2, (l + r) / 2 + 1, r, ql, qr, x, v, isDivide);
  Combine(k);
}

int Query(int k, int l, int r, int ql, int qr){
  if(qr < l || r < ql){
    return 0;
  }

  if(ql <= l && r <= qr){
    return sum[k];
  }

  LazyUpdateChildren(k);
  int ans = (Query(2 * k + 1, l, (l + r) / 2, ql, qr) + Query(2 * k + 2, (l + r) / 2 + 1, r, ql, qr)) % mod;
  Combine(k);

  return ans;
}
//-------------------------------------- Segment Tree Ends --------------------------------------//

int main(){
  int n;

  scanf("%d%d", &n, &mod);

  for(int i = 1; i <= n; ++i){
    scanf("%d", &a[i]);
  }

  PreProcess();
  BuildSegmentTree(0, 1, n);

  int q;
  scanf("%d", &q);
  while(q--){
    int t, i, j, x;
    scanf("%d%d%d", &t, &i, &j);
    if(t == 1){
      scanf("%d", &x);
      FillPrimeFactorVector(x, 1, updateVector);
      Update(0, 1, n, i, j, x, updateVector, false);
    }
    else if(t == 2){
      FillPrimeFactorVector(j, -1, updateVector);
      Update(0, 1, n, i, i, j, updateVector, true);
    }
    else{
      printf("%d\n", Query(0, 1, n, i, j));
    }
  }

  return 0;
}