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
#define N 200001
#define MOD 998244353

int fact[N], invFact[N];

int ModularExponentation(int a, int n){
  ll ans = 1;
  for( ; n; n /= 2){
    if(n % 2){
      ans = (ans * a) % MOD;
    }
    a = (1ll * a * a) % MOD;
  }
  return ans;
}

int ModularInverse(int a){
  return ModularExponentation(a, MOD - 2);
}

void Initialise(){
  fact[0] = 1;
  for(int i = 1; i < N; ++i){
    fact[i] = (1ll * i * fact[i - 1]) % MOD;
  }

  invFact[N - 1] = ModularInverse(fact[N - 1]);
  for(int i = N - 2; i > -1; --i){
    invFact[i] = (1ll * (i + 1) * invFact[i + 1]) % MOD;
  }
}

int nCr(int n, int r){
  if(r < 0 || n < 0 || n < r){
    return 0;
  }

  ll ans = fact[n];
  ans = (ans * invFact[r]) % MOD;
  ans = (ans * invFact[n - r]) % MOD;

  return ans;
}

int main(){
  int n, m;

  cin >> n >> m;

  Initialise();

  ll ans = nCr(m, n - 1);
  ans = (ans * (n - 2)) % MOD;

  for(int i = 1; i <= n - 3; ++i){
    ans = (2 * ans) % MOD;
  }

  printf("%lld\n", ans);

  return 0;
}