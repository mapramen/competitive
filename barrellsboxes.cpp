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

ll ModExp(ll a, ll n){
  ll ans = 1;
  while(n){
    if(n % 2)
      ans = (ans * a) % MOD;
    a = (a * a) % MOD;
    n /= 2;
  }
  return ans;
}

ll ModInverse(ll a){
  return ModExp(a, MOD - 2);
}

void PreProcess(){
  fact[0] = inv_fact[0] = 1;
  for(ll i = 1; i < N; i++){
    fact[i] = (i * fact[i - 1]) % MOD;
    inv_fact[i] = (ModInverse(i) * inv_fact[i - 1]) % MOD;
  }
}

ll nCr(ll n, ll r){
  if(n < 0 || r < 0 || n < r)
    return 0ll;
  else
    return (fact[n] * ((inv_fact[r] * inv_fact[n - r]) % MOD)) % MOD;
}

ll Beggar(ll m, ll n){
  if(n < 0 || m < 0 || (n == 0 && m != 0))
    return 0ll;
  else
    if(m + n == 0)
      return 1ll;
    else
      return nCr(m + n - 1, m);
}

int main(){
  ll f, w, h, p, q;

  cin >> w >> f >> h;

  PreProcess();

  q = nCr(f + w, w);
  p = 0ll;

  for(ll n = 0; n * (h + 1) <= f; n++){
    p = (p + Beggar(f - n * (h + 1), n) * Beggar(w - n + 1, n - 1)) % MOD;
    p = (p + Beggar(f - n * (h + 1), n) * Beggar(w - n - 1, n + 1)) % MOD;
    p = (p + 2 * Beggar(f - n * (h + 1), n) * Beggar(w - n, n)) % MOD;
  }

  q = ModInverse(q);

  cout << (p * q) % MOD << '\n';

  return 0;
}
