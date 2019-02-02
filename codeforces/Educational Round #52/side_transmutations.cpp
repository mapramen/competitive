#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define MOD 998244353

ll ModExp(int a, int n){
  ll x = a, y = 1 % MOD;
  while(n){
    if(n % 2){
      y = (y * x) % MOD;
    }
    x = (x * x) % MOD;
    n /= 2;
  }
  return y;
}

ll ModInv(int a){
  return ModExp(a, MOD - 2);
}

int main(){
  int n, m, a, bx;

  scanf("%d%d%d", &n, &m, &a);
  ll ans = 1;
  for(int i = 1, by = 0; i <= m; ++i, bx = by){
    scanf("%d", &by);
    ll x = ModExp(a, by - bx);
    x = (x * (x + 1)) % MOD;
    ans = (ans * x) % MOD;
  }

  ans = (ans * ModExp(a, n - 2 * bx)) % MOD;
  ans = (ans * ModExp(ModInv(2), m)) % MOD;

  printf("%lld\n", ans);

  return 0;
}
