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
int a[N];
ordered_set S[B];

int GetMod3(int x){
  return (B + (x % B)) % B;
}

ll Solve(){
  int n;
  scanf("%d%s", &n, s);

  for(int i = 1, x = 0; i <= n; ++i){
    x += s[i - 1] == '-' ? 1 : -1;
    a[i] = x;
    S[GetMod3(x)].insert({x, i});
  }

  ll ans = 0;
  for(int i = 1; i <= n; ++i){
    ordered_set& T = S[GetMod3(a[i - 1])];
    ans += (T.size() - T.order_of_key({a[i - 1], 0}));
    
    S[GetMod3(a[i])].erase({a[i], i});
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