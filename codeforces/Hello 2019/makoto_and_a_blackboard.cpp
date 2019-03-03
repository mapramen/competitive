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

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 51
#define MOD 1000000007

int inv[N], dp[N];

ll ModExp(ll a, ll n){
  ll ans = 1;
  for( ; n; n /= 2){
    if(n % 2){
      ans = (a * ans) % MOD;
    }
    a = (a * a) % MOD;
  }
  return (ans % MOD);
}

ll ModInv(ll a){
  return ModExp(a, MOD - 2);
}

void Initialise(){
  for(ll i = 1; i < N; ++i){
    inv[i] = ModInv(i);
  }
}

ll Compute(int n, int k, ll p){
  for(int i = 0; i <= n; ++i){
    dp[i] = 0;
  }

  dp[n] = 1;
  while(k--){
    for(int i = 0; i <= n; ++i){
      int val = (1ll * inv[i + 1] * dp[i]) % MOD;
      dp[i] = 0;
      for(int j = 0; j <= i; ++j){
        dp[j] = (dp[j] + val) % MOD;
      }
    }
  }

  ll ans = 0;
  p %= MOD;
  for(ll i = 0, x = 1 % MOD; i <= n; ++i, x = (x * p) % MOD){
    ans = (ans + dp[i] * x) % MOD;
  }

  return ans;
}

int main(){
  ll n, k;

  cin  >> n >> k;
  Initialise();

  ll ans = 1;
  for(ll i = 2; i * i <= n; ++i){
    if(n % i != 0){
      continue;
    }
    int m = 0;
    for( ; n % i == 0; ++m, n /= i);
    ans = (ans * Compute(m, k, i)) % MOD;
  }

  if(n != 1){
    ans = (ans * Compute(1, k, n)) % MOD;
  }

  printf("%lld\n", ans);

  return 0;
}