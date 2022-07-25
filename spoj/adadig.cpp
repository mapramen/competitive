#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 300001
#define M 19
#define MOD 1000000007

int fact[N], inv_fact[N], c[N];
map<pii,int> dp[N];

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

int nCr(int n, int r){
  if(n < 0 || r < 0 || n < r){
    return 0;
  }

  int q = (1ll * inv_fact[r] * inv_fact[n - r]) % MOD;
  return (1ll * fact[n] * q) % MOD;
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

  dp[1][{0, 0}] = 1;
  for(int i = 1; i < N; ++i){
    int ans = 0;
    for(pair<pii,int> kvp: dp[i]){
      int len = kvp.first.first, sum = kvp.first.second, cnt = kvp.second;
      
      for(int d = 2; d < 10 && d * i < N; ++d){
        dp[i * d][{len + 1, sum + d}] += cnt;
      }

      if(sum <= i){
        ans = (ans + 1ll * cnt * nCr(len + i - sum, len)) % MOD;
      }
    }
    c[i] = ans;
  }
}

int Solve(){
  int n;
  scanf("%d", &n);
  return c[n];
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