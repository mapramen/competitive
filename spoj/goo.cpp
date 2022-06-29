#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>

void Solve(){
  int n;
  scanf("%d", &n);
  
  if(n == 1){
    printf("1 1\n");
  }
  else{
    printf("%lld %lld\n", (1ll << (n - 1)), (n + 1) * (1ll << (n - 2)));
  }
}

int main(){
  int t;
  scanf("%d", &t);
  while(t--){
    Solve();
  }
  return 0;
}