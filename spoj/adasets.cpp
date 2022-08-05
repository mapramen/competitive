#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 10000001
#define MOD 1000000007

int p[N], phi[N], dp[N], inv[N];
bool prime[N];

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
  inv[0] = 1;
  for(int i = 1; i < N; ++i){
    inv[i] = (1ll * i * inv[i - 1]) % MOD;
  }

  int invf = ModularInverse(inv[N - 1]);
  for(int i = N - 1; i != -1; --i){
    inv[i] = (1ll * inv[i - 1] * invf) % MOD;
    invf = (1ll * i * invf) % MOD;
  }

  for(int i = 2; i < N; ++i){
    prime[i] = true;
  }

  for(int i = 2; i * i < N; ++i){
    for(int j = i * i; j < N; j += i){
      prime[j] = false;
    }
  }

  p[0] = 1;
  for(int i = 1; i < N; ++i){
    phi[i] = i;
    p[i] = (2 * p[i - 1]) % MOD;
  }

  for(int i = 1; i < N; ++i){
    if(!prime[i]){
      continue;
    }
    for(int j = i; j < N; j += i){
      phi[j] /= i;
      phi[j] *= (i - 1);
    }
  }

  for(int i = 1; i * i < N; ++i){
    for(int j = i * i; j < N; j += i){
      dp[j] = (dp[j] + 1ll * phi[i] * p[j / i] + 1ll * phi[j / i] * p[i]) % MOD;
    }
    dp[i * i] = (dp[i * i] - 1ll * phi[i] * p[i]) % MOD;
  }

  for(int i = 1; i < N; ++i){
    dp[i] = (1ll * inv[i] * (MOD + dp[i])) % MOD;
  }
}

int Solve(){
  int n;
  scanf("%d", &n);
  return dp[n];
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