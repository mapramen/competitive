#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>

ll Solve(){
  int n;
  ll a, b;
  scanf("%d%lld%lld", &n, &a, &b);

  vector<int> x(n + 1);
  for(int i = 1; i <= n; ++i){
    scanf("%d", &x[i]);
  }

  ll s = 0, ans = LLONG_MAX;
  for(int i = n, k = 1; i != -1; --i, ++k){
    s += x[i];
    ll ansx = (a + b) * x[i] + b * (s - 1ll * k * x[i]);
    ans = min(ans, ansx);
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