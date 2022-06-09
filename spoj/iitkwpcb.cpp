#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>

ll Solve(){
  ll n;
  scanf("%lld", &n);

  ll m = n / 2;
  while(__gcd(n, m) != 1){
    --m;
  }

  return m;
}

int main(){
  int t;
  scanf("%d", &t);
  while(t--){
    printf("%lld\n", Solve());
  }
  return 0;
}