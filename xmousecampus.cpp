#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair

ll Phi(ll n){
  ll ans = n;
  for(ll i = 2; i * i <= n; ++i){
    if(n % i != 0){
      continue;
    }
    while(n % i == 0){
      n /= i;
    }
    ans /= i;
    ans *= (i - 1);
  }
  if(n > 1){
    ans = n - 1;
  }
  return ans;
}

ll ModExp(ll x, ll n, ll mod){
  ll y = 1;
  while(n){
    if(n % 2 == 1){
      y = (y * x) % mod;
    }
    x = (x * x) % mod;
    n /= 2;
  }
  return y;
}

int main(){
  ll n, x, ans = 0;

  cin >> n >> x;

  ll m = Phi(n);
  ans = m;

  cout << m << '\n';

  for(ll i = 1; i * i <= m; ++i){
    if(n % i != 0){
      continue;
    }
    if(ModExp(x, i, n) == 1){
      ans = min(ans, i);
    }
    if(ModExp(x, m / i, n) == 1){
      ans = min(ans, m / i);
    }
  }

  ans = 1 + (n - 1) / ans;

  cout << ans << '\n';

  return 0;
}
