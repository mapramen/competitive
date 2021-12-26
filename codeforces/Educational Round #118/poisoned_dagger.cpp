#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>

ll CalculateDamage(vector<ll>&a, ll d){
  ll ans = 0;
  for(int i = 0, j = 0, n = a.size(); i < n; i = j){
    ll l = a[i], r = a[i] + d - 1;
    for(j = i; j < n && a[j] <= r; ++j){
      r = a[j] + d - 1;
    }
    ans += (r - l + 1);
  }
  return ans;
}

ll Solve(){
  int n;
  ll h;

  scanf("%d%lld", &n, &h);
  
  vector<ll> a(n);
  for(int i = 0; i < n; ++i){
    scanf("%lld", &a[i]);
  }

  ll x = 1, y = h, ans = h;
  while(x <= y){
    ll mid = x + (y - x) / 2;
    if(CalculateDamage(a, mid) >= h){
      ans = mid, y = mid - 1;
    }
    else{
      x = mid + 1;
    }
  }

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