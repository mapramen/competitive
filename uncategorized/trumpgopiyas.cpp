#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 1000001
#define MOD 1000000007

ll fact[N], inv_fact[N];

ll ModExp(int a, int n){
  ll x = a, y = 1;
  while(n){
    if(n % 2)
      y = (y * x) % MOD;
    x = (x * x) % MOD;
    n /= 2;
  }
  return y % MOD;
}

ll ModInv(int a){
  return ModExp(a, MOD - 2);
}

void Initialise(){
  fact[0] = inv_fact[0] = 1;
  for(int i = 1; i < N; ++i)
    fact[i] = (i * fact[i - 1]) % MOD;

  inv_fact[N - 1] = ModInv((int)fact[N - 1]);
  for(int i = N - 2; i > 0; --i)
    inv_fact[i] = ((i + 1) * inv_fact[i + 1]) % MOD;
}

ll nCr(int n, int r){
  if(n < 0 || r < 0 || n < r)
    return 0ll;
  else{
    ll p = fact[n];
    ll q = (inv_fact[r] * inv_fact[n - r]) % MOD;
    return (p * q) % MOD;
  }
}

ll Solve(int n, int m){
  ll ans = 0;
  for(int i = 0, r = n; i < n; ++i, --r){
    ll ansx = (nCr(n, r) * ModExp(r, m)) % MOD;
    if(i % 2)
      ans = (MOD + ans - ansx) % MOD;
    else
      ans = (ans + ansx) % MOD;
  }
  return ans;
}

int main(){
  Initialise();
  
  int n, m;

  cin >> n >> m;

  ll ans = (nCr(n, m) * Solve(n - m, n - 2)) % MOD;

  cout << ans << '\n';

  return 0;
}
