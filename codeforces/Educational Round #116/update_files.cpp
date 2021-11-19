#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>

ll Solve(){
  ll n, k;
  scanf("%lld%lld", &n, &k);

  ll a = 1, b = n - 1, ans = 0;
  while(b != 0 && a <= k){
    ll c = min(b, a);
    b -= c, a += c;
    ++ans;
  }

  ans += ((b + k - 1) / k);
  
  return ans;
}

int main(){
  int t;
  scanf("%d", &t);

  while(t--){
    printf("%lld\n", Solve());
  }

  return 0;
}