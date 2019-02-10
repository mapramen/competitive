#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair

map<ll,ll> dp;

ll Solve(ll n){
  if(dp.find(n) != dp.end())
    return dp[n];

  int k;
  for(k = 0; (1ll << k) < n; ++k);
  --k;

  ll m = (1ll << k);

  ll ans = m + Solve(m) + Solve(n - m);

  dp[n] = ans;

  return ans;
}

int main(){
  dp[1] = 0;

  ll n;

  cin >> n;
  cout << Solve(n) << '\n';

  return 0;
}
