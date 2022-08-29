#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>

int Solve(){
  ll n;
  if(scanf("%lld", &n) == EOF){
    exit(0);
  }

  ll ans = 1;
  for(ll p = 2; p * p <= n; ++p){
    if(n % p != 0){
      continue;
    }

    for( ; n % p == 0; n /= p){
      ans *= p;
    }

    ans /= p;
    ans *= (p - 1);
  }

  if(n != 1){
    ans *= (n - 1);
  }

  return ans / 2;
}

int main(){
  while(true){
    printf("%d\n", Solve());
  }
  return 0;
}