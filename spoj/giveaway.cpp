#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update

using namespace std;
using namespace __gnu_pbds;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 500001

typedef tree<
pii,
null_type,
less<pii>,
rb_tree_tag,
tree_order_statistics_node_update>
ordered_set;

int a[N];
ordered_set T[N];

void Add(int i, int x){
  pii p = {x, i};
  for( ; i < N; i += (i & -i)){
    T[i].insert(p);
  }
}

void Remove(int i, int x){
  pii p = {x, i};
  for( ; i < N; i += (i & -i)){
    T[i].erase(p);
  }
}

int Query(int i, int x){
  pii p = {x, 0};
  int ans = 0;
  for( ; i > 0; i -= (i & -i)){
    ans += (T[i].size() - T[i].order_of_key(p));
  }
  return ans;
}

int Query(int l, int r, int x){
  return Query(r, x) - Query(l - 1, x);
}

int main(){
  int n;
  scanf("%d", &n);

  for(int i = 1; i <= n; ++i){
    scanf("%d", &a[i]);
  }
  
  for(int i = 1; i <= n; ++i){
    Add(i, a[i]);
  }

  int q;
  scanf("%d", &q);

  while(q--){
    int t;
    scanf("%d", &t);

    if(t == 1){
      int i, x;
      scanf("%d%d", &i, &x);

      Remove(i, a[i]);
      Add(i, x);

      a[i] = x;
    }
    else{
      int l, r, x;
      scanf("%d%d%d", &l, &r, &x);
      printf("%d\n", Query(l, r, x));
    }
  }
  
  return 0;
}