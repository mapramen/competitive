#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update

using namespace std;
using namespace __gnu_pbds;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>

typedef tree<
pll,
null_type,
less<pll>,
rb_tree_tag,
tree_order_statistics_node_update>
ordered_set;


int main(){
  ll n, k;
  scanf("%lld%lld", &n, &k);

  ordered_set S;
  S.insert({0, 0});

  ll ans = 0;
  for(ll i = 1, s = 0; i <= n; ++i){
    ll x;
    scanf("%lld", &x);
    s += (x - k);
    
    ans += S.order_of_key({s, i});
    S.insert({s, i});
  }

  printf("%lld\n", ans);

  return 0;
}