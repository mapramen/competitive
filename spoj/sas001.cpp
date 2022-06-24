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

int main(){
  int n, k;
  scanf("%d%d", &n, &k);

  vector<int> a(n);
  for(int& x: a){
    scanf("%d", &x);
  }

  ordered_set S;
  ll max_inversion_count = LLONG_MIN, inversion_count = 0;
  int max_inversion_start_index = 0;

  for(int i = 0, j = 0; i + k - 1 < n; ++i){
    for( ; j < n && j - i < k; ++j){
      inversion_count += (S.size() - S.order_of_key({a[j] + 1, INT_MIN}));
      S.insert({a[j], j});
    }

    if(inversion_count > max_inversion_count){
      max_inversion_count = inversion_count, max_inversion_start_index = i + 1;
    }

    S.erase({a[i], i});
    inversion_count -= S.order_of_key({a[i], INT_MIN});
  }

  printf("%d %lld\n", max_inversion_start_index, max_inversion_count);

  return 0;
}