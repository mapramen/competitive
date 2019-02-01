#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 501
#define MOD 998244353

ll n, a[N];
map<ll,ll> M;

ll Power(ll p, int n){
  ll ans = 1;
  while(n--){
    ans *= p;
  }
  return ans;
}

ll GetPrimeDivisor(ll x){
  for(int n = 4; n > 1; --n){
    ll p = pow(x, 1.0 / n) - 1;
    for( ; Power(p, n) < x; ++p);
    if(Power(p, n) == x){
      return p;
    }
  }
  return 1;
}

void CollectPrimePower(ll p){
  if(p == 1){
    return ;
  }

  for(int i = 1; i <= n; ++i){
    if(a[i] % p != 0){
      continue;
    }
    while(a[i] % p == 0){
      ++M[p];
      a[i] /= p;
    }
    CollectPrimePower(a[i]);
  }
}

int main(){
  cin >> n;
  for(int i = 1; i <= n; ++i){
    cin >> a[i];
  }

  for(int i = 1; i <= n; ++i){
    CollectPrimePower(GetPrimeDivisor(a[i]));
  }

  for(int i = 1; i <= n; ++i){
    for(int j = i + 1; j <= n; ++j){
      if(i == j || a[i] == 1 || a[j] == 1){
        continue;
      }
      ll g = __gcd(a[i], a[j]);
      if(g != a[i]){
        CollectPrimePower(g);
      }
    }
  }

  ll ans = 1;
  for(auto p : M){
    ans = (ans * (p.second + 1)) % MOD;
  }

  for(int i = 1; i <= n; ++i){
    if(a[i] == 1){
      continue;
    }
    ll x = a[i];
    int c = 0;
    for(int j = i; j <= n; ++j){
      if(a[j] == x){
        ++c;
        a[j] = 1;
      }
    }
    ans = ((c + 1) * ans) % MOD;
    ans = ((c + 1) * ans) % MOD;
  }

  cout << ans << '\n';

  fflush(stdout);

  return 0;
}
