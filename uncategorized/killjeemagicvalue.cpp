#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define MOD 1000000007

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

ll Fun(int n, int m, int mod){
  ll a = 0, b = 1 % mod, f = 1 % mod, ans = 0;
  for(int i = 1; i <= m; ++i){
    b = (a + b) % mod;
    a = (b - a + mod) % mod;
    f = (f * i) % mod;
    if(i >= n)
      ans = (ans + f * b) % mod;
  }
  return ans;
}

ll Query(int n, int m, int k){
  ll ans = (Fun(n, m, MOD) - Fun(n, m, k) + MOD) % MOD;
  ans = (ans * ModInv(1ll * k)) % MOD;
  return ans;
}

int main(){
  int t;

  cin >> t;
  while(t--){
    int n, m, k;
    cin >> n >> m >> k;
    cout << Query(n, m, k) << '\n';
  }

  return 0;
}
