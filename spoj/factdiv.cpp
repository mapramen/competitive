#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 1000001
#define MOD 1000000007

int a[N], c[N];
bool is_prime[N];

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
  for(int i = 1; i < N; ++i){
    is_prime[i] = true;
    c[i] = 1;
  }

  for(int i = 2; i * i < N; ++i){
    if(!is_prime[i]){
      continue;
    }

    for(int j = i * i; j < N; j += i){
      if(is_prime[j]){
        is_prime[j] = false;
      }
    }
  }

  for(int i = 2; i < N; ++i){
    if(!is_prime[i]){
      continue;
    }

    for(ll x = i; x < N; x *= i){
      for(int y = x; y < N; y += x){
        ++a[y];
      }
    }

    for(int j = i, s = 1; j < N; j += i){
      c[j] = (1ll * ModularInverse(s) * c[j]) % MOD;
      s += a[j];
      a[j] = 0;
      c[j] = (1ll * s * c[j]) % MOD;
    }
  }

  c[0] = 1;
  for(int i = 1; i < N; ++i){
    c[i] = (1ll * c[i - 1] * c[i]) % MOD;
  }

  c[0] = 0;
  for(int i = 1; i < N; ++i){
    c[i] = (c[i] + c[i - 1]) % MOD;
  }
}

int Solve(){
  int l, r;
  scanf("%d%d", &l, &r);
  return (MOD + c[r] - c[l - 1]) % MOD;
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