#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define B 10
#define N (1 << B)

ll dp[N];

int main(){
  int n;
  scanf("%d", &n);

  while(n--){
    ll x;
    scanf("%lld", &x);

    int mask = 0;
    for( ; x > 0; x /= B){
      mask |= (1 << (x % B));
    }
    ++dp[mask];
  }

  for(int k = 0; k < B; ++k){
    for(int mask = 0; mask < N; ++mask){
      if((mask & (1 << k)) != 0){
        continue;
      }
      dp[mask] += dp[mask ^ (1 << k)];
    }
  }

  for(int mask = 0; mask < N; ++mask){
    dp[mask] = dp[mask] * (dp[mask] - 1) / 2;
  }

  for(int k = 0; k < B; ++k){
    for(int mask = 0; mask < N; ++mask){
      if((mask & (1 << k)) != 0){
        continue;
      }
      dp[mask] -= dp[mask ^ (1 << k)];
    }
  }

  ll ans = 0;
  for(int mask = 1; mask < N; ++mask){
    ans += dp[mask];
  }

  printf("%lld\n", ans);

  return 0;
}