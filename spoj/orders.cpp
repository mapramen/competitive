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
#define N 200001

ordered_set S;
int a[N], ans[N];

void Solve(){
  int n;
  scanf("%d", &n);

  for(int k = 1; k <= n; ++k){
    scanf("%d", &a[k]);
  }

  for(int i = 1; i <= n; ++i){
    S.insert(i);
  }

  for(int k = n; k != 0; --k){
    int i = *S.find_by_order(S.size() - a[k] - 1);
    ans[k] = i;
    S.erase(i);
  }

  for(int k = 1; k <= n; ++k){
    printf("%d ", ans[k]);
  }
  printf("\n");
}

int main(){
  int t;
  scanf("%d", &t);
  while(t--){
    Solve();
  }
  return 0;
}