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
#define MOD 998244353

int d[N], damageSum[N], inv[N];

int ModularExponentation(int a, int n){
  ll ans = 1;
  for( ; n > 0; n /= 2){
    if(n % 2 == 1){
      ans = (ans * a) % MOD;
    }
    a = (1ll * a * a) % MOD;
  }
  return ans;
}

int ModularInverse(int a){
  return ModularExponentation(a, MOD - 2);
}

void Initialise(int n){
  for(int i = 1, s = 0; i <= n; ++i){
    inv[i] = ModularInverse(i);
  }

  sort(d + 1, d + n + 1);
  for(int i = 1, s = 0; i <= n; ++i){
    s = (s + d[i]) % MOD;
    damageSum[i] = s;
  }
}

int DamageRangeSum(int l, int r){
  if(l > r){
    return 0;
  }

  if(l == 0){
    return damageSum[r];
  }

  return (MOD + damageSum[r] - damageSum[l - 1]) % MOD;
}

int QueryX(int k, int a, int l, int r){
  int ans = (1ll * (k - a) * inv[k]) % MOD;
  ans = (1ll * ans * DamageRangeSum(l, r)) % MOD;
  return ans;
}

int Query(int n, int a, int b){
  if(d[n] < b){
    return 0;
  }

  int i = lower_bound(d, d + n + 1, b) - d;
  int k = n - i + 1;

  if(k < a){
    return 0;
  }

  int ans = QueryX(k, a, i, n);

  if(i != 1){
    ans = (ans + QueryX(k + 1, a, 1, i - 1)) % MOD;
  }

  return ans;
}

int main(){
  int n, q;

  scanf("%d%d", &n, &q);

  for(int i = 1; i <= n; ++i){
    scanf("%d", &d[i]);
  }

  Initialise(n);

  while(q--){
    int a, b;
    scanf("%d%d", &a, &b);
    printf("%d\n", Query(n, a, b));
  }

  return 0;
}