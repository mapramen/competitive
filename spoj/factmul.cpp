#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>

ll MOD = 109546051211, BN1 = 62792, MOD1 = 186583, BN2 = -19955, MOD2 = 587117;

int FactMul(int n, int mod){
  int ans = 1, f = 1;
  for(int i = 2; i <= n; ++i){
    f = (1ll * i * f) % mod;
    ans = (1ll * f * ans) % mod;
  }
  return ans;
}

int main(){
  int n;
  scanf("%d", &n);

  ll ans = (1ll * FactMul(n, MOD2) * BN1 * MOD1 + 1ll * FactMul(n, MOD1) * BN2 * MOD2) % MOD;
  ans = (MOD + ans) % MOD;

  printf("%lld\n", ans);
  
  return 0;
}