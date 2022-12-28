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
#define N 100001

ordered_set S;

vector<int> Solve(){
  int n;
  scanf("%d", &n);

  vector<int> a(n);
  for(int& x: a){
    scanf("%d", &x);
  }

  for(int i = 1; i <= n; ++i){
    S.insert(i);
  }

  for(int i = n - 1; i != -1; --i){
    int x = *S.find_by_order(i - a[i]);
    
    a[i] = x;
    S.erase(x);
  }

  return a;
}

int main(){
  int t;
  scanf("%d", &t);
  while(t--){
    for(int x: Solve()){
      printf("%d ", x);
    }
    printf("\n");
  }
  return 0;
}