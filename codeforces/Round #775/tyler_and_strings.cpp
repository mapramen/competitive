#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 200001
#define MOD 998244353

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

int s[N], t[N], c[N], T[N];

void Update(int i, int x){
  for( ; i < N; i += (i & -i)){
    T[i] = (T[i] + x) % MOD;
  }
}

int Query(int i){
  int ans = 0;
  for( ; i > 0; i -= (i & -i)){
    ans = (ans + T[i]) % MOD;
  }
  return ans;
}

int Cost(int x){
  int k = c[x];
  return k == 0 ? 0 : (1ll * fact[k] * inv_fact[k - 1]) % MOD;
}

int main(){
  int n, m;
  scanf("%d%d", &n, &m);
  
  for(int i = 1; i <= n; ++i){
    int x;
    scanf("%d", &x);
    ++c[x];
  }

  for(int j = 1; j <= m; ++j){
    scanf("%d", &t[j]);
  }

  Initialise();

  int base_count = fact[n];
  for(int x = 1; x < N; ++x){
    base_count = (1ll * base_count * inv_fact[c[x]]) % MOD;
    Update(x, Cost(x));
  }

  bool are_equal = true;
  int ans = 0;

  for(int i = 1, l = n; i <= min(n, m); ++i, --l){
    base_count = (1ll * base_count * inv_fact[l]) % MOD;
    base_count = (1ll * base_count * fact[l - 1]) % MOD;

    int x = t[i];
    ans = (ans + 1ll * Query(x - 1) * base_count) % MOD;

    if(c[x] == 0){
      are_equal = false;
      break;
    }

    Update(x, -Cost(x));
    base_count = (1ll * base_count * Cost(x)) % MOD;
    --c[x];
    Update(x, Cost(x));
  }

  ans = (ans + (n < m && are_equal)) % MOD;
  ans = (MOD + ans) % MOD;

  printf("%d\n", ans);

  return 0;
}