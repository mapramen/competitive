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

ll fact[N], invFact[N];

ll ModExp(int a, int n){
  ll x = a, y = 1 % MOD;
  while(n){
    if(n % 2)
      y = (y * x) % MOD;
    x = (x * x) % MOD;
    n /= 2;
  }
  return y;
}

ll ModInv(int a){
  return ModExp(a, MOD - 2);
}

void Initialise(){
  fact[0] = 1 % MOD;
  for(int i = 1; i < N; ++i){
    fact[i] = (i * fact[i - 1]) % MOD;
  }

  invFact[N - 1] = ModInv((int)fact[N - 1]);
  for(int i = N - 2; i > -1; --i){
    invFact[i] = ((i + 1) * invFact[i + 1]) % MOD;
  }
}

ll nCr(int n, int r){
  if(r < 0 || n < 0 || n < r){
    return 0ll;
  }

  ll p = fact[n];
  ll q = (invFact[r] * invFact[n - r]) % MOD;
  return (p * q) % MOD;
}

ll StirlingNumber2(int n, int k){
  if(n < k)
    return 0ll;

  ll ans = 0;
  for(int j = 0, c = k % 2 ? -1 : 1; j <= k; ++j, c = -c){
    ll ansx = (invFact[k - j] * invFact[j]) % MOD;
    ansx = (ansx * ModExp(j, n)) % MOD;
    ans = (ans + MOD + c * ansx) % MOD;
  }

  return ans;
}

int main(){
  int n, k;

  cin >> n >> k;
  k = n - k;

  if(k <= 0 || k > n){
    printf("0\n");
    return 0;
  }

  Initialise();

  if(k == n){
    cout << fact[n] << '\n';
    return 0;
  }

  ll ans = (nCr(n, k) * StirlingNumber2(n, k)) % MOD;
  ans = (2 * fact[k] * ans) % MOD;

  cout << ans << '\n';

  return 0;
}