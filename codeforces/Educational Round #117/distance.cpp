#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>

pii Solve(){
  int x, y;
  scanf("%d%d", &x, &y);

  if((x + y) % 2 == 1){
    return {-1, -1};
  }

  int m = (x + y) / 2;
  return x < y ? make_pair(0, m) : make_pair(m, 0);
}

int main(){
  int t;
  scanf("%d", &t);
  while(t--){
    auto [x, y] = Solve();
    printf("%d %d\n", x, y);
  }
  return 0;
}