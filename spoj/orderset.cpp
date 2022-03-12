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

char op[10];

int main(){
  ordered_set S;

  int q;
  scanf("%d", &q);

  while(q--){
    int x;
    scanf("%s%d", op, &x);

    if(op[0] == 'I'){
      S.insert(x);
    }
    else if(op[0] == 'D'){
      S.erase(x);
    }
    else if(op[0] == 'C'){
      printf("%lu\n", S.order_of_key(x));
    }
    else if(x > S.size()){
      printf("invalid\n");
    }
    else{
      printf("%d\n", *S.find_by_order(x - 1));
    }
  }

  return 0;
}