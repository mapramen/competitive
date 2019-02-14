#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define MOD 2000000033

int ModExp(int a, int n){
  ll x = a, y = 1;
  while(n){
    if(n % 2)
      y = (y * x) % MOD;
    x = (x * x) % MOD;
    n /= 2;
  }
  return (int)y;
}

int ModInverse(int a){
  return ModExp(a, MOD - 2);
}

int nCr(int n, int r){
  if(n < 0 || r < 0 || n < r)
    return 0;
  else{
    int p = 1, q = 1;
    r = max(r, n - r);
    for(int i = 0; i < n - r; ++i){
      p = (1ll * p * (n - i)) % MOD;
      q = (1ll * q * (n - r - i)) % MOD;
    }
    int ans = (1ll * p * ModInverse(q)) % MOD;
    return ans;
  }
}

int main(){
  int n, m, k;

  cin >> n >> m >> k;

  ll ans = nCr(n + m - 2, n - 1);

  ans *= ((n * m) % MOD - k + MOD);

  ans %= MOD;

  cout << ans << '\n';

  return 0;
}
