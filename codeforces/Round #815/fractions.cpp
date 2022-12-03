#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>

int Solve(){
  int a, b, c, d;
  scanf("%d%d%d%d", &a, &b, &c, &d);

  ll x = 1ll * a * d, y = 1ll * c * b;

  if(x > y){
    swap(x, y);
  }

  ll g = __gcd(max(1ll, x), y);
  x /= g, y /= g;

  if(y == 0){
    return 0;
  }

  if(x == 0){
    return 1;
  }

  if(y == 1){
    return 0;
  }

  if(x == 1){
    return 1;
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