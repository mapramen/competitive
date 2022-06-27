#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>

ll Query(ll n){
  ll ans = 0;
  for(int k = 0; k < 60; ++k){
    if((1ll << k) <= n){
      ans += (1ll << k);
    }
  }
  return ans;
}

ll Query(ll l, ll r){
  return Query(r) - Query(l - 1);
}

int main(){
  ll l, r;
  scanf("%lld%lld", &l, &r);
  printf("%lld\n", Query(l, r));
  return 0;
}