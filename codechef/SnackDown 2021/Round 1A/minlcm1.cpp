#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>

void Solve(){
  ll x, k;
  scanf("%lld%lld", &x, &k);
  printf("%lld %lld\n", 2 * x, x * k * (x * k - 1));
}

int main(){
  int t;
  scanf("%d", &t);

  while(t--){
    Solve();
  }

  return 0;
}