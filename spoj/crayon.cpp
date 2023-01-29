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

char op[10];

int GetLECount(ordered_set& S, int x){
  return S.order_of_key({x, INT_MAX});
}

int main(){
  int n;
  scanf("%d", &n);

  map<int,pii> M;
  ordered_set start_points, end_points;

  for(int i = 1, segment_cnt = 0; i <= n; ++i){
    scanf("%s", op);

    if(op[0] == 'D'){
      ++segment_cnt;
      int l, r;
      scanf("%d%d", &l, &r);
      M[segment_cnt] = {l, r};
      start_points.insert({l, segment_cnt});
      end_points.insert({r, segment_cnt});
    }
    else if(op[0] == 'C'){
      int k;
      scanf("%d", &k);
      start_points.erase({M[k].first, k});
      end_points.erase({M[k].second, k});
      M.erase(k);
    }
    else{
      int l, r;
      scanf("%d%d", &l, &r);
      printf("%d\n", GetLECount(start_points, r) - GetLECount(end_points, l - 1));
    }
  }

  return 0;
}