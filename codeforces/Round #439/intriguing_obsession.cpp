#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 5001
#define MOD 998244353

ll fact[N], inv_fact[N];

ll ModExp(ll a, ll n){
  ll ans = 1 % MOD;
  while(n){
    if(n % 2)
      ans = (ans * a) % MOD;
    a = (a * a) % MOD;
    n /= 2;
  }
  return ans;
}

ll ModInv(ll a){
  return ModExp(a, 1ll * MOD - 2);
}

void Initialise(){
  fact[0] = 1;
  for(int i = 1; i < N; ++i)
    fact[i] = (i * fact[i - 1]) % MOD;

  inv_fact[0] = 1;
  inv_fact[N - 1] = ModInv(fact[N - 1]);
  for(int i = N - 2; i > 0; --i)
    inv_fact[i] = ((i + 1) * inv_fact[i + 1]) % MOD;
}

ll nCr(int n, int r){
  if(r < 0 || n < 0 || n < r)
    return 0ll;
  else{
    ll ans = fact[n];
    ans = (ans * inv_fact[r]) % MOD;
    ans = (ans * inv_fact[n - r]) % MOD;
    return ans;
  }
}

ll Compute(int a, int b){
  ll ans = 0;
  for(int k = 0; k <= min(a, b); ++k)
    ans += ((nCr(a, k) * nCr(b, k)) % MOD * fact[k]) % MOD;
  return ans % MOD;
}

int main(){
  int a, b, c;

  cin >> a >> b >> c;

  Initialise();

  ll ans = Compute(a, b);
  ans = (ans * Compute(b, c)) % MOD;
  ans = (ans * Compute(a, c)) % MOD;

  cout << ans << '\n';

  return 0;
}
