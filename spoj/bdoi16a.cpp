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

ordered_set S;
map<int,int> M;
char op[2];

void Add(){
  int x;
  scanf("%s%d", op, &x);

  int p;
  if(op[0] == 'F'){
    p = S.empty() ? 0 : S.begin()->first - 1;
  }
  else{
    p = S.empty() ? 0 : S.rbegin()->first + 1;
  }

  M[x] = p;
  S.insert({p, x});
}

void Remove(){
  scanf("%s", op);

  int x = op[0] == 'F' ? S.begin()->second : S.rbegin()->second;
  int p = M[x];

  M.erase(x);
  S.erase({p, x});
}

int Query(){
  int x;
  scanf("%s%d", op, &x);

  if(op[0] == 'D'){
    return S.find_by_order(x - 1)->second;
  }

  return 1 + S.order_of_key({M[x], x});
}

void Solve(){
  int n;
  scanf("%d", &n);

  S.clear();
  M.clear();

  while(n--){
    int t;
    scanf("%d", &t);

    if(t == 1){
      Add();
    }
    else if(t == 2){
      Remove();
    }
    else{
      printf("%d\n", Query());
    }
  }
}

int main(){
  int t;
  scanf("%d", &t);
  for(int k = 1; k <= t; ++k){
    printf("Case %d:\n", k);
    Solve();
  }
  return 0;
}