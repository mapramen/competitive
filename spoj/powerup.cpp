#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define MOD 1000000007

int ModularExponentation(int a, int n, int mod){
  a %= mod;
  int ans = 1;
  for( ; n > 0; n /= 2){
    if(n % 2 == 1){
      ans = (1ll * ans * a) % mod;
    }
    a = (1ll * a * a) % mod;
  }
  return ans;
}

int Solve(){
  int a, b, c;
  scanf("%d%d%d", &a, &b, &c);

  if(a == -1){
    exit(0);
  }

  if(a % MOD == 0 && b != 0){
    return 0;
  }

  return ModularExponentation(a, ModularExponentation(b, c, MOD - 1), MOD);
}

int main(){
  while(true){
    printf("%d\n", Solve());
  }
  return 0;
}