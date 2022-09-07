#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>

ll Solve(){
  int w, h;
  scanf("%d%d", &w, &h);
  
  if(w == 0){
    exit(0);
  }

  int g = __gcd(w, h);
  return 1ll * (w / g) * (h / g);
}

int main(){
  while(true){
    printf("%lld\n", Solve());
  }
  return 0;
}