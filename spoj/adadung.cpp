#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 10000001
#define MOD 1000000007

int fact[N], inv_fact[N], dp[N];

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

void Initialise(){
  fact[0] = 1;
  for(int i = 1; i < N; ++i){
    fact[i] = (1ll * i * fact[i - 1]) % MOD;
  }

  inv_fact[N - 1] = ModularInverse(fact[N - 1]);
  for(int i = N - 2; i > -1; --i){
    inv_fact[i] = (1ll * (i + 1) * inv_fact[i + 1]) % MOD;
  }

  dp[0] = 1;
  for(int i = 1, x = -1; i < N; ++i, x = -x){
    dp[i] = (dp[i - 1] + 1ll * x * inv_fact[i]) % MOD;
  }

  for(int i = 1; i < N; ++i){
    dp[i] = (1ll * dp[i] * fact[i]) % MOD;
    dp[i] = (MOD + dp[i]) % MOD;
  }
}

int Solve(){
  int n;
  scanf("%d", &n);
  return dp[n];
}

int main(){
  Initialise();

  int t;
  scanf("%d", &t);
  
  while(t--){
    printf("%d\n", Solve());
  }
  
  return 0;
}