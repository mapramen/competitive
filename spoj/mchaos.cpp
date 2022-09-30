#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update

using namespace std;
using namespace __gnu_pbds;

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>

typedef tree<
string,
null_type,
less<string>,
rb_tree_tag,
tree_order_statistics_node_update>
ordered_set;

ordered_set S;

int main(){
  int n;
  scanf("%d", &n);

  vector<string> v(n);
  for(string& s: v){
    cin >> s;
  }
  sort(v.begin(), v.end());

  ll ans = 1ll * n * (n - 1) / 2;
  for(string& s: v){
    reverse(s.begin(), s.end());
    ans -= S.order_of_key(s);
    S.insert(s);
  }

  printf("%lld\n", ans);

  return 0;
}