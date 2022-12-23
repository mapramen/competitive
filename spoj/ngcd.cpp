#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define B 15
#define M (1 << B)

int primes[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47};
ll dp[M];

int GetMask(ll n){
  int mask = 0;
  for(int i = 0; i < B; ++i){
    if(n % primes[i] == 0){
      mask |= (1 << i);
    }
  }
  return mask;
}

ll Solve(){
  int n;
  scanf("%d", &n);

  for(int mask = 0; mask < M; ++mask){
    dp[mask] = 0;
  }

  while(n--){
    ll x;
    scanf("%lld", &x);
    ++dp[GetMask(x)];
  }

  ll ans = dp[0];
  for(int i = 0; i < B; ++i){
    ans += dp[(1 << i)];
  }

  reverse(dp, dp + M);

  for(int i = 0; i < B; ++i){
    for(int mask = 0; mask < M; ++mask){
      if((mask & (1 << i)) != 0){
        dp[mask] += dp[(mask ^ (1 << i))];
      }
    }
  }

  for(int mask = 0; mask < M; ++mask){
    dp[mask] *= (dp[mask] - 1);
  }

  for(int i = 0; i < B; ++i){
    for(int mask = 0; mask < M; ++mask){
      if((mask & (1 << i)) != 0){
        dp[mask] -= dp[(mask ^ (1 << i))];
      }
    }
  }

  reverse(dp, dp + M);

  ans += dp[0];
  for(int i = 0; i < B; ++i){
    ans += dp[(1 << i)];
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