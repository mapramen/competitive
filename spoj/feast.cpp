#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 5001

ll dp[N];

ll Solve(){
  int m, n;
  scanf("%d%d", &m, &n);

  vector<pii> a(n);
  for(pii& p: a){
    scanf("%d%d", &p.second, &p.first);
  }
  sort(a.begin(), a.end());

  for(int i = 0; i <= m; ++i){
    dp[i] = 0;
  }
  dp[0] = 1;

  ll ans = 0;
  for(int d = m; d != 0; --d){
    if(m % d != 0){
      continue;
    }

    for( ; !a.empty() && d <= a.back().first; a.pop_back()){
      for(int v = a.back().second, x = m; x >= v; --x){
        dp[x] += dp[x - v];
      }
    }

    ans += dp[(m / d)];
  }

  return ans;
}

int main(){
  int t;
  scanf("%d", &t);
  for(int k = 1; k <= t; ++k){
    printf("Case %d: %lld\n", k, Solve());
  }
  return 0;
}