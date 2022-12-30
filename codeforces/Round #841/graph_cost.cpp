#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 1000001

ll c[N];

ll Solve(){
  int n;
  ll m;
  scanf("%d%lld", &n, &m);

  for(int i = n; i != 0; --i){
    ll x = n / i;
    x *= (x - 1);
    x /= 2;

    for(int j = 2 * i; j <= n; j += i){
      x -= c[j];
    }

    c[i] = x;
  }

  ll ans = 0;
  for(int i = n; i > 1; --i){
    ll z = (min(c[i], m) / (i - 1)) * (i - 1);
    m -= z;
    ans += 1ll * i * (z / (i - 1));
  }

  return m == 0 ? ans : -1;
}

int main(){
  int t;
  scanf("%d", &t);
  while(t--){
    printf("%lld\n", Solve());
  }
  return 0;
}