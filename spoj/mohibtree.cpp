#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>

ll Calculate(ll n){
  if(n % 2 == 0){
    return n / 2 - 1;
  }

  ll d = 3;
  for( ; d * d <= n && n % d != 0; ++d);

  return d * d > n ? 0 : 1 + Calculate(n - d);
}

ll Solve(){
  ll n;
  scanf("%lld", &n);
  return Calculate(n);
}

int main(){
  int t;
  scanf("%d", &t);
  for(int k = 1; k <= t; ++k){
    printf("Case #%d: %lld\n", k, Solve());
  }
  return 0;
}