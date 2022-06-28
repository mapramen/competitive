#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define MOD 10000007

int Solve(){
  int n;
  scanf("%d", &n);

  vector<ll> a(n);
  for(ll& x: a){
    scanf("%lld", &x);
  }

  ll ans = 0;
  for(int k = 0; k <= 32; ++k){
    int c = 0;
    for(ll& x: a){
      c += ((x & (1ll << k)) != 0);
    }
    ans += 2ll * c * (n - c);
  }

  return ans % MOD;
}

int main(){
  int t;
  scanf("%d", &t);
  for(int k = 1; k <= t; ++k){
    printf("Case %d: %d\n", k, Solve());
  }
  return 0;
}