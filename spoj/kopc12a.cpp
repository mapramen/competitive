#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>

ll Solve(){
  int n;
  scanf("%d", &n);

  vector<pii> a(n + 1);
  
  for(int i = 1; i <= n; ++i){
    scanf("%d", &a[i].first);
  }

  for(int i = 1; i <= n; ++i){
    scanf("%d", &a[i].second);
  }

  sort(a.begin(), a.end());

  vector<ll> prefix_cost(n + 2), suffix_cost(n + 2);
  
  for(int i = 1, px = 0, sum_weight = 0; i <= n; ++i){
    prefix_cost[i] = prefix_cost[i - 1] + 1ll * sum_weight * (a[i].first - px);
    px = a[i].first, sum_weight += a[i].second;
  }

  for(int i = n, px = 0, sum_weight = 0; i > 0; --i){
    suffix_cost[i] = suffix_cost[i + 1] + 1ll * sum_weight * (px - a[i].first);
    px = a[i].first, sum_weight += a[i].second;
  }

  ll ans = LLONG_MAX;
  for(int i = 1; i <= n; ++i){
    ans = min(ans, prefix_cost[i] + suffix_cost[i]);
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