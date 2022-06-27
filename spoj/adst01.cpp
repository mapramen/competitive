#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define MOD 1000000007

int ModularExponentation(int a, ll n){
  int ans = 1;
  for( ; n > 0; n /= 2){
    if(n % 2 == 1){
      ans = (1ll * ans * a) % MOD;
    }
    a = (1ll * a * a) % MOD;
  }
  return ans;
}

int ModularInverse(int a){
  return ModularExponentation(a, MOD - 2);
}

int Solve(){
  ll n;
  scanf("%lld", &n);

  ll ans = ModularExponentation(10, n) - 1;
  ans = (50 * ans) % MOD;
  ans = (ModularInverse(81) * ans) % MOD;

  ans = ((1ll * ((4 * n) % MOD) * ModularInverse(9)) % MOD + ans) % MOD;

  return (MOD + ans) % MOD;
}

int main(){
  int t;
  scanf("%d", &t);
  while(t--){
    printf("%d\n", Solve());
  }
  return 0;
}