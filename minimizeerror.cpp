#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 1001

ll a[N], b[N];

int main(){
  int n, k1, k2;

  scanf("%d%d%d", &n, &k1, &k2);
  for(int i = 1; i <= n; ++i)
    scanf("%lld", &a[i]);

  for(int i = 1; i <= n; ++i)
    scanf("%lld", &b[i]);

  for(int q = k1 + k2; q > 0; --q){
    ll m = -1, k = 0;
    for(int i = 1; i <= n; ++i){
      ll x = abs(a[i] - b[i]);
      if(x > m)
        m = x, k = i;
    }
    if(a[k] - b[k] >= 0)
      --a[k];
    else
      ++a[k];
  }

  ll ans = 0;
  for(int i = 1; i <= n; ++i){
    ll x = abs(a[i] - b[i]);
    ans += x * x;
  }

  printf("%lld\n", ans);

  return 0;
}
