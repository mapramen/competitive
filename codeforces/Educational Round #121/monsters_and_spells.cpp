#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>

ll Solve(){
  int n;
  scanf("%d", &n);

  vector<int> k(n), h(n);
  for(int i = 0; i < n; ++i){
    scanf("%d", &k[i]);
  }

  for(int i = 0; i < n; ++i){
    scanf("%d", &h[i]);
  }

  vector<pii> v(n);
  for(int i = 0; i < n; ++i){
    v[i] = {k[i] - h[i] + 1, k[i]};
  }
  sort(v.begin(), v.end());

  ll ans = 0;
  for(int i = 0; i < n; ){
    int l = v[i].first, r = v[i].second;
    for( ; i < n && v[i].first <= r; ++i){
      r = max(r, v[i].second);
    }

    ll m = (r - l + 1);
    ans += (m * (m + 1) / 2);
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