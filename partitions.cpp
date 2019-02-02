#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 200001
#define MOD 1000000007

ll fact[N], inv_fact[N];

ll ModExp(int a, int n){
  ll x = a, y = 1 % MOD;
  while(n){
    if(n % 2)
      y = (y * x) % MOD;
    x = (x * x) % MOD;
    n /= 2;
  }
  return y;
}

ll ModInv(int a){
  return ModExp(a, MOD - 2);
}

void Initialise(){
  fact[0] = 1 % MOD;
  for(int i = 1; i < N; ++i)
    fact[i] = (i * fact[i - 1]) % MOD;

  inv_fact[N - 1] = ModInv((int)fact[N - 1]);
  for(int i = N - 2; i > -1; --i)
    inv_fact[i] = ((i + 1) * inv_fact[i + 1]) % MOD;
}

ll StirlingNumber2(int n, int k){
  if(n < k)
    return 0ll;

  ll ans = 0;
  for(int j = 0, c = k % 2 ? -1 : 1; j <= k; ++j, c = -c){
    ll ansx = (inv_fact[k - j] * inv_fact[j]) % MOD;
    ansx = (ansx * ModExp(j, n)) % MOD;
    ans = (ans + MOD + c * ansx) % MOD;
  }

  return ans;
}

int main(){
  int n, k;

  scanf("%d%d", &n, &k);

  ll s = 0;
  for(int i = 1; i <= n; ++i){
    int j;
    scanf("%d", &j);
    s = (s + j) % MOD;
  }

  Initialise();

  ll c = (StirlingNumber2(n, k) + (n - 1) * StirlingNumber2(n - 1, k)) % MOD;
  ll ans = (c * s) % MOD;

  printf("%lld\n", ans);

  return 0;
}
