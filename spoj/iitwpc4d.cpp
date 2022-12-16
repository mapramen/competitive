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

int a[N];
ordered_set S;

vector<int> Solve(){
  int n;
  scanf("%d", &n);

  for(int i = 1; i <= n; ++i){
    scanf("%d", &a[i]);
  }

  for(int i = 1; i <= n; ++i){
    S.insert(i);
  }

  vector<int> v;
  for(int i = n; i != 0; --i){
    int r = i - a[i] - 1;
    if(r < 0 || r >= i){
      break;
    }

    int x = *S.find_by_order(r);
    v.push_back(x);
    S.erase(x);
  }

  if(v.size() != n){
    v.clear();
    v.push_back(-1);
  }

  reverse(v.begin(), v.end());

  S.clear();
  return v;
}

int main(){
  int t;
  scanf("%d", &t);
  for(int k = 1; k <= t; ++k){
    printf("Test : %d\n", k);

    for(int x: Solve()){
      printf("%d ", x);
    }
    printf("\n");
  }
  return 0;
}