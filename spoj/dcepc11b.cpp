#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>

int ModularExponentation(int a, int n, int mod){
  int ans = 1;
  for( ; n > 0; n /= 2){
    if(n % 2 == 1){
      ans = (1ll * ans * a) % mod;
    }
    a = (1ll * a * a) % mod;
  }
  return ans;
}

int ModularInverse(int a, int mod){
  return ModularExponentation(a, mod - 2, mod);
}

int Solve(){
  int n, p;
  scanf("%d%d", &n, &p);

  if(n >= p){
    return 0;
  }

  int ans = p - 1;
  for(int i = p - 1; i > n; --i){
    ans = (1ll * ans * ModularInverse(i, p)) % p;
  }

  return ans;
}

int main(){
  int t;
  scanf("%d", &t);
  while(t--){
    printf("%d\n", Solve());
  }
  return 0;
}