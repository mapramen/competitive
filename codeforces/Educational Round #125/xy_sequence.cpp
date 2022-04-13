#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>

ll Solve(){
  int n, B, x, y;
  scanf("%d%d%d%d", &n, &B, &x, &y);

  ll a = 0, s = 0;
  while(n--){
    if(a + x <= B){
      a += x;
    }
    else{
      a -= y;
    }
    s += a;
  }

  return s;
}

int main(){
  int t;
  scanf("%d", &t);
  while(t--){
    printf("%lld\n", Solve());
  }
  return 0;
}