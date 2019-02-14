#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair

vector<ll> GetPowersLE(ll a, ll n){
  vector<ll> ans;

  ans.PB(1ll);
  for(ll x = 1; x <= n / a; ){
    x *= a;
    ans.PB(x);
  }

  return ans;
}

int main(){
  ll x, y, l, r, ans = 0;

  cin >> x >> y >> l >> r;

  vector<ll> v1 = GetPowersLE(x, r), v2 = GetPowersLE(y, r), v;

  for(auto x : v1){
    for(auto y : v2){
      auto z = x + y;
      if(l <= z && z <= r)
        v.PB(z);
    }
  }

  v.PB(l - 1);
  v.PB(r + 1);
  sort(v.begin(), v.end());
  v.erase(unique(v.begin(), v.end()), v.end());

  for(int i = 0; i + 1 < v.size(); i++)
    ans = max(ans, v[i + 1] - v[i] - 1);

  cout << ans << '\n';

  return 0;
}
