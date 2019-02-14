#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 10000019
#define MOD N

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
  return ModExp(a, MOD - 2);
}

void PreProcess(){
  fact[0] = inv_fact[0] = 1;

  for(int i = 1; i < N; ++i)
    fact[i] = (i * fact[i - 1]) % MOD;

  inv_fact[N - 1] = ModInv(fact[N - 1]);
  for(int i = N - 2; i > 0; --i)
    inv_fact[i] = ((i + 1) * inv_fact[i + 1]) % MOD;
}

int nCr(int n, int r){
  if(n < 0 || r < 0 || n < r)
    return 0;
  else{
    ll ans = fact[n];
    ans = (ans * inv_fact[n - r]) % MOD;
    ans = (ans * inv_fact[r]) % MOD;
    return (int)ans;
  }
}

int Query(ll n, ll m, ll r){
  if(r < 2)
    return 0;
  else{
    ll ans = ((n % MOD) * (m % MOD)) % MOD;
    n += (m - 2);
    r -= 2;
    while(n){
      ans = (ans * nCr(n % MOD, r % MOD)) % MOD;
      n /= MOD;
      r /= MOD;
    }
    return (int)ans;
  }
}

int main(){
  PreProcess();

  int t;
  cin >> t;
  while(t--){
    ll n, m, r;
    cin >> n >> m >> r;
    cout << Query(n, m, r) << '\n';
  }

  return 0;
}
