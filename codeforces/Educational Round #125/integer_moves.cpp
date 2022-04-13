#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>

int Solve(){
  int x, y;
  scanf("%d%d", &x, &y);

  if(x == 0 && y == 0){
    return 0;
  }

  int n = x * x + y * y;
  for(int i = 1; i * i <= n; ++i){
    if(i * i == n){
      return 1;
    }
  }

  return 2;
}

int main(){
  int t;
  scanf("%d", &t);
  while(t--){
    printf("%d\n", Solve());
  }
  return 0;
}