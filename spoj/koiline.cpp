#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update

using namespace std;
using namespace __gnu_pbds;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 200001

typedef tree<
pii,
null_type,
less<pii>,
rb_tree_tag,
tree_order_statistics_node_update>
ordered_set;

int a[N];

int main(){
  int n;
  scanf("%d", &n);

  ordered_set S;
  for(int i = 1; i <= n; ++i){
    int x;
    scanf("%d", &x);
    S.insert({x, i});
  }

  for(int i = 1; i <= n; ++i){
    scanf("%d", &a[i]);
  }

  for(int i = n; i != -1; --i){
    auto it = S.find_by_order(a[i]);
    a[i] = it->first;
    S.erase(it);
  }

  for(int i = 1; i <= n; ++i){
    printf("%d\n", a[i]);
  }

  return 0;
}