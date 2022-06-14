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

ordered_set S;

void Solve(){
  int n, k;
  scanf("%d%d", &n, &k);

  if(n == 0){
    exit(0);
  }

  S.clear();
  for(int i = 1; i <= n; ++i){
    S.insert(i);
  }

  for(int i = 1; S.size() > 1; ){
    auto it = S.lower_bound(i);
    if(it == S.end()){
      i = *S.begin();
    }
    else{
      i = *it;
    }

    int rj = S.order_of_key(i) + 1 + ((k - 1) % S.size());
    if(rj > S.size()){
      rj -= S.size();
    }

    i = *S.find_by_order(rj - 1);
    S.erase(i);
  }

  printf("%d %d %d\n", n, k, *S.begin());
}

int main(){
  while(true){
    Solve();
  }
  return 0;
}