#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 2001
#define MOD 998244353

int fact[N], inv_fact[N], dp[N][N];

void InitializeDP(){
  dp[0][0] = 1;
  for(int i = 1; i < N; ++i){
    for(int j = 1; j <= i; ++j){
      dp[i][j] = (1ll * j * dp[i - 1][j] + dp[i - 1][j - 1]) % MOD;
    }
  }
}

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

void Initialize(){
  fact[0] = 1;
  for(int i = 1; i < N; ++i){
    fact[i] = (1ll * i * fact[i - 1]) % MOD;
  }

  inv_fact[N - 1] = ModularInverse(fact[N - 1]);
  for(int i = N - 2; i > -1; --i){
    inv_fact[i] = (1ll * (i + 1) * inv_fact[i + 1]) % MOD;
  }

  InitializeDP();
}

int Solve(){
  int n, m, k;
  scanf("%d%d%d", &n, &m, &k);

  int ans = 0;
  for(int i = 1, p = (1ll * ((m + 1) / 2) * ModularInverse(m)) % MOD, x = 1, f = 1; i <= k; ++i){
    x = (1ll * x * p) % MOD;
    f = (1ll * f * (n - i + 1)) % MOD;
    
    int ansx = (1ll * x * f) % MOD;
    ansx = (1ll * ansx * inv_fact[i]) % MOD;
    ansx = (1ll * ansx * dp[k][i]) % MOD;
    ansx = (1ll * ansx * fact[i]) % MOD;

    ans = (ans + ansx) % MOD;
  }
  ans = (1ll * ans * ModularExponentation(m, n)) % MOD;

  return ans;
}

int main(){
  Initialize();

  int t;
  scanf("%d", &t);
  
  while(t--){
    printf("%d\n", Solve());
  }
  
  return 0;
}