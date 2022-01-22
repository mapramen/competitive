#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>

map<int,ll> dp;

ll DP(int n){
  if(n == 0){
    return 0ll;
  }

  auto it = dp.find(n);
  if(it != dp.end()){
    return it->second;
  }

  ll ans = max(1ll * n, DP(n / 2) + DP(n / 3) + DP(n / 4));
  
  dp[n] = ans;
  return ans;
}

ll Solve(){
  int n;

  if(scanf("%d", &n) == EOF){
    exit(0);
  }

  return DP(n);
}

int main(){
  while(true){
    printf("%lld\n", Solve());
  }
  return 0;
}