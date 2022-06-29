#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>

int F(ll n){
  int ans = 0;
  while(n != 0){
    ans += (n % 10);
    n /= 10;
  }
  return ans;
}

ll Solve(){
  ll n;
  scanf("%lld", &n);

  while(n % F(n) != 0){
    ++n;
  }

  return n;
}

int main(){
  int t;
  scanf("%d", &t);
  while(t--){
    printf("%lld\n", Solve());
  }
  return 0;
}