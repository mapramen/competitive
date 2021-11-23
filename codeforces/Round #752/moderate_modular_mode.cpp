#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>

int Solve(){
  int x, y;
  scanf("%d%d", &x, &y);
  
  if(y % x == 0){
    return x;
  }

  if(y < x){
    return x + y;
  }

  return y - (y % x) / 2;
}

int main(){
  int t;
  scanf("%d", &t);

  while(t--){
    printf("%d\n", Solve());
  }
  
  return 0;
}