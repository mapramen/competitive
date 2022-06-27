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
#define N 200000

map<int,ordered_set> M;
int a[N];

int main(){
  int n, q;
  scanf("%d%d", &n, &q);

  for(int i = 0; i < n; ++i){
    scanf("%d", &a[i]);
  }

  for(int i = 0; i < n; ++i){
    M[a[i]].insert(i);
  }

  while(q--){
    int i, ai;
    scanf("%d%d", &i, &ai);

    M[a[i]].erase(i);

    a[i] = ai;
    M[a[i]].insert(i);

    printf("%lu\n", M[a[i]].order_of_key(i));
  }

  return 0;
}