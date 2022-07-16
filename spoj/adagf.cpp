#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>

int main(){
  int n;
  scanf("%d", &n);

  ll ans = 0;

  map<int,int> dp;
  vector<pii> a;

  while(n--){
    int x;
    scanf("%d", &x);

    a.push_back({x, 1});
    for(pii p: dp){
      a.push_back({__gcd(x, p.first), p.second});
    }
    dp.clear();
    
    for(pii& p: a){
      ans += 1ll * p.first * p.second;
      dp[p.first] += p.second;
    }
    a.clear();
  }

  printf("%lld\n", ans);
  
  return 0;
}