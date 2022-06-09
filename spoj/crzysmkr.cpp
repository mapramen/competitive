#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define MOD 11

int Solve(){
  ll n;
  scanf("%lld", &n);
  n %= MOD;
  ll ans = (30 * n) % MOD;
  return (MOD - ans) % MOD;
}

int main(){
  int t;
  scanf("%d", &t);
  while(t--){
    printf("%d\n", Solve());
  }
  return 0;
}