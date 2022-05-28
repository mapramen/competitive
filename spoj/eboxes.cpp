#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>

ll Solve(){
  ll n, k, t, f;
  scanf("%lld%lld%lld%lld", &n, &k, &t, &f);
  return (k * f - n) / (k - 1);
}

int main(){
  int t;
  scanf("%d", &t);
  while(t--){
    printf("%lld\n", Solve());
  }
  return 0;
}