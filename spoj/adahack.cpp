#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define B 6

ll MOD = 100000000003;
ll x[B];

ll ModularExponentation(ll a, ll n){
  __int128 x = (MOD + (a % MOD)) % MOD, y = 1;
  for( ; n > 0; n /= 2){
    if(n % 2 == 1){
      y = (y * x) % MOD;
    }
    x = (x * x) % MOD;
  }
  return y;
}

ll ModularInverse(ll a){
  return ModularExponentation(a, MOD - 2);
}

ll Solve(){
  for(int i = 0; i < B; ++i){
    if(scanf("%lld", &x[i]) == EOF){
      exit(0);
    }
  }

  vector<pll> v;
  for(int i = 1; i < B; ++i){
    v.push_back({x[i - 1], x[i]});
  }
  sort(v.begin(), v.end());

  __int128 a = 1, b = 0;
  for(int i = 1; i < v.size(); ++i){
    if(v[i].first == v[i - 1].first){
      continue;
    }

    __int128 y = (MOD + v[i].second - v[i - 1].second) % MOD;
    a = (y * ModularInverse(v[i].first - v[i - 1].first)) % MOD;
    b = (v[i].second - a * v[i].first) % MOD;
    b = (MOD + b) % MOD;
  }

  return (a * x[B - 1] + b) % MOD;
}

int main(){
  while(true){
    printf("%lld\n", Solve());
  }
  return 0;
}