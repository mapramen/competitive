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
#define N 400001
#define K 301
#define B 20
#define M (1 << B)
#define MOD 1000000007

int n, m, a[N];
ll numberToPrimeMask[K];
vector<int> primes, eulerForPrime;
char s[100];

ll ModularExponentation(int a, int n){
  ll ans = 1;
  for( ; n; n /= 2){
    if(n % 2){
      ans = (1ll * ans * a) % MOD;
    }
    a = (1ll * a * a) % MOD;
  }
  return ans;
}

ll ModularInverse(int a){
  return ModularExponentation(a, MOD - 2);
}

void Initialise(){
  for(int i = 2; i < K; ++i){
    bool isPrime = true;
    for(int j = 2; j * j <= i && isPrime; ++j){
      isPrime = (i % j != 0);
    }
    if(isPrime){
      primes.push_back(i);
      eulerForPrime.push_back((ModularInverse(i) * (i - 1)) % MOD);
    }
  }
  
  m = primes.size();

  for(int i = 2; i < K; ++i){
    for(int j = 0; j < m; ++j){
      if(i % primes[j] == 0){
        numberToPrimeMask[i] |= (1ll << j);
      }
    }
  }
}

//----------------------------------------- Segment Tree -----------------------------------------//
ll length[M], lazyProduct[M], lazyPrimeMask[M], product[M], primeMask[M];

void Combine(int k){
  product[k] = (product[2 * k + 1] * product[2 * k + 2]) % MOD;
  primeMask[k] = primeMask[2 * k + 1] | primeMask[2 * k + 2];
}

void BuildSegmentTree(int k, int l, int r){
  if(l == r){
    product[k] = a[l];
    primeMask[k] = numberToPrimeMask[a[l]];
  }
  else{
    BuildSegmentTree(2 * k + 1, l, (l + r) / 2);
    BuildSegmentTree(2 * k + 2, (l + r) / 2 + 1, r);
    Combine(k);
  }
  length[k] = r - l + 1;
  lazyProduct[k] = 1;
  lazyPrimeMask[k] = 0;
}

void UpdateNode(int k, ll x, ll mask){
  lazyProduct[k] = (x * lazyProduct[k]) % MOD;
  product[k] = (ModularExponentation(x, length[k]) * product[k]) % MOD;
  
  lazyPrimeMask[k] |= mask;
  primeMask[k] |= mask;
}

void LazyUpdateChildren(int k){
  if(lazyPrimeMask[k] == 0){
    return ;
  }

  UpdateNode(2 * k + 1, lazyProduct[k], lazyPrimeMask[k]);
  UpdateNode(2 * k + 2, lazyProduct[k], lazyPrimeMask[k]);

  lazyProduct[k] = 1;
  lazyPrimeMask[k] = 0;
}

void Update(int k, int l, int r, int ql, int qr, int x){
  if(qr < l || r < ql){
    return ;
  }

  if(ql <= l && r <= qr){
    UpdateNode(k, x, numberToPrimeMask[x]);
    return ;
  }

  LazyUpdateChildren(k);
  Update(2 * k + 1, l, (l + r) / 2, ql, qr, x);
  Update(2 * k + 2, (l + r) / 2 + 1, r, ql, qr, x);
  Combine(k);
}

pll Query(int k, int l, int r, int ql, int qr){
  if(qr < l || r < ql){
    return make_pair(1ll, 0ll);
  }

  if(ql <= l && r <= qr){
    return make_pair(product[k], primeMask[k]);
  }

  LazyUpdateChildren(k);
  ll product1, product2, mask1, mask2;
  tie(product1, mask1) = Query(2 * k + 1, l, (l + r) / 2, ql, qr);
  tie(product2, mask2) = Query(2 * k + 2, (l + r) / 2 + 1, r, ql, qr);
  Combine(k);

  return make_pair((product1 * product2) % MOD, mask1 | mask2);
}
//-------------------------------------- Segment Tree Ends --------------------------------------//

void PreProcess(){
  Initialise();
  BuildSegmentTree(0, 1, n);
}

void Update(int l, int r, int x){
  return Update(0, 1, n, l, r, x);
}

int Query(int l, int r){
  ll product, mask;
  tie(product, mask) = Query(0, 1, n, l, r);

  for(int k = 0; k < m; ++k){
    if((mask & (1ll << k)) == 0){
      continue;
    }
    product = (product * eulerForPrime[k]) % MOD;
  }

  return product;
}

int main(){
  int q;

  scanf("%d%d", &n, &q);
  for(int i = 1; i <= n; ++i){
    scanf("%d", &a[i]);
  }

  PreProcess();

  while(q--){
    int l, r;
    scanf("%s%d%d", s, &l, &r);
    if(s[0] == 'T'){
      printf("%d\n", Query(l, r));
    }
    else{
      int a;
      scanf("%d", &a);
      Update(l, r, a);
    }
  }

  return 0;
}