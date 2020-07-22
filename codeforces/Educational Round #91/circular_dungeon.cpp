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
#define MOD 998244353

ll a[N];

int ModExp(int a, int n){
  int ans = 1;
  for( ; n > 0; n /= 2){
    if(n % 2 == 1){
      ans = (1ll * a * ans) % MOD;
    }
    a = (1ll * a * a) % MOD;
  }
  return ans % MOD;
}

int ModInv(int a){
  return ModExp(a, MOD - 2);
}

int main(){
  int n;

  scanf("%d", &n);
  for(int i = 1; i <= n; ++i){
    scanf("%lld", &a[i]);
  }
  sort(a + 1, a + n + 1, greater<int>());

  for(int i = 2; i <= n; ++i){
    a[i] += a[i - 1];
  }

  ll q = ModInv(n);
  for(int k = 1; k <= n; ++k){
    ll p = 0;
    for(int i = 1, j, x = 0; i <= n; i = j + 1, ++x){
      j = min(n, i + k - 1);
      p += x * (a[j] - a[i - 1]);
    }
    int ans = (1ll * (p % MOD) * q) % MOD;
    printf("%d ", ans);
  }
  printf("\n");

  return 0;
}