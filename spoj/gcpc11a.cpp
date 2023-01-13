#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>

ll PrimePowerInFactorial(ll n, ll p){
  ll ans = 0;
  for( ; n >= p; n /= p){
    ans += n / p;
  }
  return ans;
}

ll CalculatePower(ll p, ll a, ll& b){
  int k = 0;
  for( ; b % p == 0; b /= p, ++k);
  return PrimePowerInFactorial(a, p) / k;
}

ll Solve(){
  ll a, b;
  scanf("%lld%lld", &a, &b);

  ll ans = LLONG_MAX;
  for(ll p = 2; p * p <= b; ++p){
    if(b % p != 0){
      continue;
    }
    ans = min(ans, CalculatePower(p, a, b));
  }

  if(b != 1){
    ans = min(ans, CalculatePower(b, a, b));
  }

  return ans;
}

int main(){
  int t;
  scanf("%d", &t);
  for(int k = 1; k <= t; ++k){
    printf("%lld\n", Solve());
  }
  return 0;
}