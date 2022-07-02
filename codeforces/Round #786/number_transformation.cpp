#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>

void Solve(){
  int x, y;
  scanf("%d%d", &x, &y);
  printf("%d %d\n", y % x == 0 ? 1 : 0, y % x == 0 ? y / x : 0);
}

int main(){
  int t;
  scanf("%d", &t);
  while(t--){
    Solve();
  }
  return 0;
}