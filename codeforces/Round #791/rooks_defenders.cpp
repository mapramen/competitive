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

map<int,int> X, Y;
ordered_set SX, SY;

bool Check(ordered_set& S, int l, int r){
  int cnt = S.order_of_key(r + 1) - S.order_of_key(l);
  return cnt == r - l + 1;
}

int main(){
  int n, q;
  scanf("%d%d", &n, &q);

  while(q--){
    int t;
    scanf("%d", &t);

    if(t == 1){
      int x, y;
      scanf("%d%d", &x, &y);
      ++X[x], ++Y[y];
      SX.insert(x), SY.insert(y);
    }
    else if(t == 2){
      int x, y;
      scanf("%d%d", &x, &y);
      
      if(--X[x] == 0){
        SX.erase(x);
      }

      if(--Y[y] == 0){
        SY.erase(y);
      }
    }
    else{
      int x1, y1, x2, y2;
      scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
      printf("%s\n", Check(SX, x1, x2) || Check(SY, y1, y2) ? "Yes" : "No");
    }
  }

  return 0;
}