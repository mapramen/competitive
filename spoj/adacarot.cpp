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

int Solve(){
  int n;
  if(scanf("%d", &n) == EOF){
    exit(0);
  }

  int ans = 0;
  for(int i = 1; i < n; ++i){
    ans = (ans + 1ll * ModularExponentation(i, n - i - 1) * ModularExponentation(n - i, i - 1)) % MOD;
  }

  for(int i = 1; i <= n; ++i){
    ans = (1ll * i * ans) % MOD;
  }

  return ans;
}

int main(){
  while(true){
    printf("%d\n", Solve());
  }
  return 0;
}