#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define MOD 1000000007

int ModularExponentation(int a, int n){
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
  int n, l;
  scanf("%d%d", &n, &l);
  
  if(n == 0 && l == 0){
    exit(0);
  }

  int ans = (MOD + ModularExponentation(n, l) - 1) % MOD;
  ans = (1ll * n * ans) % MOD;
  ans = (1ll * ModularInverse(n - 1) * ans) % MOD;

  return ans;
}

int main(){
  while(true){
    printf("%d\n", Solve());
  }
  return 0;
}