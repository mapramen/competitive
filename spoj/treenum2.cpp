#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define B 60

ll MOD = (1ll << 32), p3[B], dp[B];

void Initialize(){
  p3[0] = 1;
  for(int k = 1; k < B; ++k){
    p3[k] = (3 * p3[k - 1]) % MOD;
  }

  dp[1] = 1;
  for(int k = 2; k < B; ++k){
    ll p2 = (1ll << (k - 1)) % MOD;
    dp[k] = (2ll * dp[k - 1] + p2 * p3[k - 1]) % MOD;
  }
}

ll Query(ll n){
  if(n == 0){
    return 0ll;
  }

  int k = 63 - __builtin_clzll(n);
  
  ll c = (n - (1ll << k) + 1) % MOD;
  ll ans = (c * p3[k]) % MOD;

  return (dp[k] + ans + Query(n - (1ll << k))) % MOD;
}

ll Query(ll l, ll r){
  ll ans = (Query(r) - Query(l - 1)) % MOD;
  return (MOD + ans) % MOD;
}

ll Solve(){
  ll l, r;
  scanf("%lld%lld", &l, &r);
  return Query(l, r);
}

int main(){
  Initialize();

  int t;
  scanf("%d", &t);
  
  while(t--){
    printf("%lld\n", Solve());
  }
  
  return 0;
}