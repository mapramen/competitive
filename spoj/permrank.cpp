#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update

using namespace std;
using namespace __gnu_pbds;

typedef long long ll;

typedef tree<
int,
null_type,
less<int>,
rb_tree_tag,
tree_order_statistics_node_update>
ordered_set;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define MOD 1000000007

ordered_set S;

int Solve(){
  int n;
  scanf("%d", &n);

  for(int i = 1; i <= n; ++i){
    S.insert(i);
  }

  int ans = 0;
  for(int i = 1; i <= n; ++i){
    int x;
    scanf("%d", &x);

    ans = (1ll * (n - i + 1) * ans) % MOD;
    ans = (ans + S.order_of_key(x)) % MOD;

    S.erase(x);
  }

  return (ans + 1) % MOD;
}

int main(){
  int t;
  scanf("%d", &t);
  while(t--){
    printf("%d\n", Solve());
  }
  return 0;
}