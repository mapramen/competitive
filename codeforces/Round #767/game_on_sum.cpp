#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 1000001
#define MOD 1000000007
#define INV2 500000004

int fact[N], inv_fact[N];

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
}

int nCr(int n, int r){
  if(n < 0 || r < 0 || n < r){
    return 0;
  }

  int q = (1ll * inv_fact[r] * inv_fact[n - r]) % MOD;
  return (1ll * fact[n] * q) % MOD;
}

int Calculate(int n, int m){
  if(n == m){
    return n;
  }

  int ans = 0;
  for(int i = 1, p = 2; i <= m; ++i, p = (p * 2) % MOD){
    int ansx = nCr(n - i - 1, m - i);
    ansx = (1ll * p * ansx) % MOD;
    ansx = (1ll * i * ansx) % MOD;
    ans = (ans + ansx) % MOD;
  }

  for(int i = 1; i <= n; ++i){
    ans = (1ll * INV2 * ans) % MOD;
  }

  return ans;
}

int Solve(){
  int n, m, k;
  scanf("%d%d%d", &n, &m, &k);
  return (1ll * Calculate(n, m) * k) % MOD;
}

int main(){
  int t;
  scanf("%d", &t);
  Initialise();
  while(t--){
    printf("%d\n", Solve());
  }
  return 0;
}