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
#define N 500001
#define MOD 998244353

int c[N];

int ModularExponentation(int a, int n){
  int ans = 1;
  for( ; n > 0; n /= 2){
    if(n % 2 == 1){
      ans = (1ll * a * ans) % MOD;
    }
    a = (1ll * a * a) % MOD;
  }
  return ans % MOD;
}

int ModularInverse(int a){
  return ModularExponentation(a, MOD - 2);
}

int Solve(){
  int n;

  scanf("%d", &n);
  for(int i = 1; i <= n; ++i){
    int x;
    scanf("%d", &x);
    ++c[x];
  }

  for(int i = 1; i < N; ++i){
    for(int j = 2 * i; j < N; j += i){
      c[i] += c[j];
    }
  }

  int ans = 0;
  for(int i = N - 1; i > 0; --i){
    int val = 0;
    for(int j = 2 * i; j < N; j += i){
      val = (val + c[j]) % MOD;
    }
    
    c[i] = (1ll * c[i] * c[i] - val) % MOD;

    ans = (ans + 1ll * i * c[i]) % MOD;
  }

  ans = (1ll * ans * (n + 1)) % MOD;
  ans = (1ll * ans * (2 * n + 1)) % MOD;

  ans = (1ll * ans * ModularInverse((6ll * n * n) % MOD)) % MOD;

  for(int i = 1; i < N; ++i){
    c[i] = 0;
  }

  return (ans + MOD) % MOD;
}

int main(){
  int t;
  scanf("%d", &t);
  while(t--){
    printf("%d\n", Solve());
  }
  return 0;
}