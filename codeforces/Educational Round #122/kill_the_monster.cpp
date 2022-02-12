#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>

ll Ceil(ll a, ll b){
  return (a + b - 1) / b;
}

bool Check(ll hc, ll dc, ll hm, ll dm, ll k, ll a, ll w, ll x){
  ll A = max(0ll, (hc + x * a - 1) / dm);
  ll B = Ceil(hm, dc + (k - x) * w) - 1;
  return A >= B;
}

bool Solve(){
  ll hc, dc, hm, dm, k, a, w;
  scanf("%lld%lld%lld%lld%lld%lld%lld", &hc, &dc, &hm, &dm, &k, &w, &a);
  
  for(ll x = 0; x <= k; ++x){
    if(Check(hc, dc, hm, dm, k, a, w, x)){
      return true;
    }
  }

  return false;
}

int main(){
  int t;
  scanf("%d", &t);
  while(t--){
    printf("%s\n", Solve() ? "YES" : "NO");
  }
  return 0;
}