#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>

void Solve(){
  ll a, b, c;
  scanf("%lld%lld%lld", &a, &b, &c);

  ll x = ((c - a) / b + 1) * b + a, y = b, z = c;
  printf("%lld %lld %lld\n", x, y, z);
}

int main(){
  int t;
  scanf("%d", &t);
  while(t--){
    Solve();
  }
  return 0;
}