#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update

using namespace std;
using namespace __gnu_pbds;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>

typedef tree<
pii,
null_type,
less<pii>,
rb_tree_tag,
tree_order_statistics_node_update>
ordered_set;

ordered_set S;

ll Solve(){
  int n;
  scanf("%d", &n);

  ll ans = 0;
  while(n--){
    int x;
    scanf("%d", &x);
    ans += (S.size() - S.order_of_key({x, n}));
    S.insert({x, n});
  }

  S.clear();
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