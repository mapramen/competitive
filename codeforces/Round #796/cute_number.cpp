#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 1000001

int a[N];

ll Cost(int n, int k){
  if(1ll * k * k + k < a[1]){
    return LLONG_MAX;
  }

  ll low = max(0ll, 1ll * k * k - a[1]), high = 1ll * k * k + k - a[1];
  ll x = low;

  for(int i = 1; low <= high; ++k){
    ll l = 1ll * k * k, mid = 1ll * k * k + k, r = 1ll * (k + 1) * (k + 1);
    if(a[n] + x < l){
      break;
    }

    i = upper_bound(a + i, a + n + 1, mid - x) - a - 1;
    high = min(high, mid - a[i]);

    if(i != n){
      ++i;
      low = max(low, r - a[i]);
    }
  }

  return low <= high ? low : LLONG_MAX;
}

int main(){
  int n;
  scanf("%d", &n);

  for(int i = 1; i <= n; ++i){
    scanf("%d", &a[i]);
  }

  ll ans = LLONG_MAX;
  for(int k = 1; ans == LLONG_MAX; ++k){
    ans = Cost(n, k);
  }

  printf("%lld\n", ans);

  return 0;
}