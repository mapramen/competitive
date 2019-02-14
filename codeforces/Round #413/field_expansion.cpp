#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 100001

int n;
vector<ll> c;

int Compute(ll a, ll b, ll w, ll h){
  int ans = -1;
  vector< set< pll > > dp(n + 1);
  dp[0].insert(MP(w, h));

  for(int i = 0; i <= n && ans == -1; i++){
    for(auto p : dp[i]){
      tie(w, h) = p;
      if((a <= w && b <= h) || (b <= w && a <= h)){
        ans = i;
        break;
      }
      else if(i != n){
        if(w < a)
          dp[i + 1].insert(MP(c[i] * w, h));

        if(h < b)
          dp[i + 1].insert(MP(w, c[i] * h));
      }
    }
  }

  return ans;
}

int main(){
  ll a, b, w, h;

  scanf("%lld%lld%lld%lld%d", &a, &b, &w, &h, &n);

  for(int i = 1; i <= n; i++){
    ll x;
    scanf("%lld", &x);
    c.PB(x);
  }

  sort(c.begin(), c.end(), greater<ll>());

  cout << Compute(a, b, w, h) << '\n';

  return 0;
}
