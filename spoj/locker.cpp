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

int Solve(){
  ll n;
  scanf("%lld", &n);

  if(n == 1){
    return 1;
  }

  int r = n % 3;
  ll k = n / 3;

  if(r == 0){
    return ModularExponentation(3, k);
  }

  if(r == 1){
    return (4ll * ModularExponentation(3, k - 1)) % MOD;
  }

  return (2ll * ModularExponentation(3, k)) % MOD;
}

int main(){
  int t;
  scanf("%d", &t);
  while(t--){
    printf("%d\n", Solve());
  }
  return 0;
}