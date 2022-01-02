#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
 
#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 200001

int a[N];
 
ll Solve(){
  int n;
  ll k;
  scanf("%d%lld", &n, &k);

  for(int i = 1; i <= n; ++i){
    scanf("%d", &a[i]);
  }
  sort(a + 1, a + n + 1);

  ll s = 0;
  for(int i = 1; i <= n; ++i){
    s += a[i];
  }

  if(s <= k){
    return 0;
  }

  s -= a[1];

  ll ans = LLONG_MAX;
  for(int i = n; i != 0; --i){
    ll ki = k - s;
    ll m = ki / (n - i + 1);
    
    if(ki < 0 && ki % (n - i + 1) != 0){
      --m;
    }

    ll ansx = max(0ll, a[1] - m) + (n - i);
    ans = min(ans, ansx);

    s -= a[i];
  }

  return ans;
}
 
int main(){
  int t;
  scanf("%d", &t);
  while(t--){
    printf("%lld\n", Solve());
  }
  return 0;
}