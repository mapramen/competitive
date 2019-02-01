#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define MOD1 1000000007
#define MOD2 1000000009

ll ModExp(ll a, int n, int mod){
  ll ans = 1;
  while(n){
    if(n % 2)
      ans = (a * ans) % mod;
    a = (a * a) % mod;
    n /= 2;
  }
  return ans;
}

ll ModInv(ll a, int mod){
  return ModExp(a, mod - 2, mod);
}

ll Expectation(ll n, int mod){
  n = n % mod;
  ll p = (n * (n - 1)) % mod, q = (2 * (mod + 2 * n - 3)) % mod;
  return (p * ModInv(q, mod)) % mod;
}

int main(){
  ll t;
  scanf("%lld", &t);
  while(t--){
    ll n;
    scanf("%lld", &n);
    printf("%lld %lld\n", Expectation(n, MOD1), Expectation(n, MOD2));
  }
  return 0;
}
