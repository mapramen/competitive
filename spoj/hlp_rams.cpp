#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>

void Solve(){
  ll n;
  scanf("%lld", &n);

  int z = __builtin_popcountll(n);
  printf("%lld %lld\n", n + 1 - (1ll << z), (1ll << z));
}

int main(){
  int t;
  scanf("%d", &t);
  while(t--){
    Solve();
  }
  return 0;
}