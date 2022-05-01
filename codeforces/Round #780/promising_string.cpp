#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update

using namespace std;
using namespace __gnu_pbds;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 200001
#define B 3

typedef tree<
pii,
null_type,
less<pii>,
rb_tree_tag,
tree_order_statistics_node_update>
ordered_set;

char s[N];
ordered_set S[B];

int GetMod3(int x){
  return (B + (x % B)) % B;
}

ll Solve(){
  int n;
  scanf("%d%s", &n, s);

  S[0].insert({0, 0});

  ll ans = 0;
  for(int i = 1, x = 0; i <= n; ++i){
    x += s[i - 1] == '-' ? 1 : -1;

    ordered_set& T = S[GetMod3(x)];

    ans += T.order_of_key({x, i});
    T.insert({x, i});
  }

  for(int k = 0; k < B; ++k){
    S[k].clear();
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