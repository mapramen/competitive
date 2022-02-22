#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>

ll Solve(){
  int n, k;
  scanf("%d%d", &n, &k);
  --n, --k;
  k = min(k, n - k);

  ll ans = 1;
  for(int i = 1; i <= k; ++i){
    int g = __gcd(ans, 1ll * i);
    ans /= g;
    ans *= ((n - i + 1) / (i / g));
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