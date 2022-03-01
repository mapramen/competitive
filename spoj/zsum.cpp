#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define MOD 10000007

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

int D(int n, int k){
  return (ModularExponentation(n, k) + ModularExponentation(n, n)) % MOD;
}

int Solve(){
  int n, k;
  scanf("%d%d", &n, &k);

  if(n == 0 && k == 0){
    exit(0);
  }

  return (D(n, k) + 2 * D(n - 1, k)) % MOD;
}

int main(){
  while(true){
    printf("%d\n", Solve());
  }
  return 0;
}