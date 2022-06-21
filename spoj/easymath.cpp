#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define B 5

void AddToLCM(vector<ll>& v, ll x){
  for(ll y: v){
    x /= __gcd(y, x);
  }
  v.push_back(x);
}

ll GetCount(ll n, vector<ll>& v){
  for(ll y: v){
    n /= y;
  }
  return n;
}

ll Calculate(ll a, ll d, ll n){
  ll ans = 0;
  for(int mask = 0; mask < (1 << B); ++mask){
    vector<ll> v;
    
    for(int i = 0; i < B; ++i){
      if((mask & (1 << i)) == 0){
        continue;
      }
      AddToLCM(v, a + i * d);
    }

    ll ansx = GetCount(n, v);
    ans += __builtin_popcount(mask) % 2 == 0 ? ansx : -ansx;
  }
  return ans;
}

ll Solve(){
  ll n, m, a, d;
  scanf("%lld%lld%lld%lld", &n, &m, &a, &d);
  return Calculate(a, d, m) - Calculate(a, d, n - 1);
}

int main(){
  int t;
  scanf("%d", &t);
  while(t--){
    printf("%lld\n", Solve());
  }
  return 0;
}