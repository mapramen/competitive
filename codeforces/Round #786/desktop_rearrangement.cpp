#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update

using namespace std;
using namespace __gnu_pbds;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 1001

typedef tree<
int,
null_type,
less<int>,
rb_tree_tag,
tree_order_statistics_node_update>
ordered_set;

char s[N][N];
ordered_set S;

int GetIndex(int n, int m, int x, int y){
  return (y - 1) * n + x;
}

int main(){
  int n, m, q;
  scanf("%d%d%d", &n, &m, &q);

  for(int x = 0; x < n; ++x){
    scanf("%s", s[x]);
  }

  for(int x = 1; x <= n; ++x){
    for(int y = 1; y <= m; ++y){
      if(s[x - 1][y - 1] == '*'){
        S.insert(GetIndex(n, m, x, y));
      }
    }
  }

  while(q--){
    int x, y;
    scanf("%d%d", &x, &y);
    
    int z = GetIndex(n, m, x, y);
    if(S.find(z) == S.end()){
      S.insert(z);
    }
    else{
      S.erase(z);
    }

    printf("%lu\n", S.size() - S.order_of_key(S.size() + 1));
  }
  
  return 0;
}