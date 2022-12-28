#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define B 31

int z[B];

pll Solve(){
  int n;
  scanf("%d", &n);

  for(int i = 1; i <= n; ++i){
    int x;
    scanf("%d", &x);
    for(int k = 0; k < B; ++k){
      z[k] += ((x & (1 << k)) == 0);
    }
  }

  ll p = 0;
  for(int k = 0; k < B; ++k){
    ll cnt = 1ll * n * (n - 1) / 2 - 1ll * z[k] * (z[k] - 1) / 2;
    p += cnt * (1 << k);
    z[k] = 0;
  }

  ll q = 1ll * n * (n - 1) / 2;
  ll g = __gcd(p, q);
  return {p / g, q / g};
}

int main(){
  int t;
  scanf("%d", &t);
  while(t--){
    pll ans = Solve();
    printf("%llu/%llu\n", ans.first, ans.second);
  }
  return 0;
}