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
  if(scanf("%lld", &n) == EOF){
    exit(0);
  }

  int ans = (ModularExponentation(2, n + 1) + 3 + ModularExponentation(MOD - 1, n)) % MOD;
  ans = (1ll * ans * ModularInverse(6)) % MOD;

  return ans;
}

int main(){
  while(true){
    printf("%d\n", Solve());
  }
  return 0;
}