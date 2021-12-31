#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define B 26
#define N 23
#define M (1 << N)
#define MOD 998244353 

int C[N + 1][B], P[N + 1][B], t[M], dp[M];

void InitialiseDP(int n, int mask){
  if(n == -1){
    if(mask != 0){
      int ans = 1;
      for(int k = 0; k < B; ++k){
        ans = (1ll * ans * (1 + P[0][k])) % MOD;
      }
      dp[mask] = ans;
    }
    return;
  }

  for(int k = 0; k < B; ++k){
    P[n][k] = P[n + 1][k];
  }

  InitialiseDP(n - 1, mask);

  for(int k = 0; k < B; ++k){
    P[n][k] = min(P[n + 1][k], C[n][k]);
  }

  InitialiseDP(n - 1, mask | (1 << n));
}

void PreProcess(int n){
  for(int k = 0; k < B; ++k){
    P[n][k] = INT_MAX;
  }
  InitialiseDP(n - 1, 0);
}

int main(){
  int n, m;
  scanf("%d", &n);

  for(int i = 0; i < n; ++i){
    string s;
    cin >> s;

    for(char c: s){
      ++C[i][c - 'a'];
    }
  }

  m = (1 << n);
  PreProcess(n);

  for(int x = 0, y = m - 1; x < y; ++x, --y){
    swap(dp[x], dp[y]);
  }

  for(int i = 0; i < n; ++i){
    int imask = (1 << i);
    for(int mask = m - 1; mask != 0; --mask){
      if((mask & imask) != 0){
        dp[mask] = (MOD + dp[mask] - dp[(mask ^ imask)]) % MOD;
      }
    }
  }

  for(int x = 0, y = m - 1; x < y; ++x, --y){
    swap(dp[x], dp[y]);
  }
  dp[0] = 0;

  int s = 0;
  for(int mask = m - 1; mask != 0; --mask){
    s = (s + dp[mask]) % MOD;
  }

  for(int i = 0; i < n; ++i){
    int imask = (1 << i);
    for(int mask = m - 1; mask != 0; --mask){
      if((mask & imask) != 0){
        dp[mask] = (dp[mask] + dp[(mask ^ imask)]) % MOD;
        t[mask] = t[(mask ^ imask)] + (i + 1);
      }
    }
  }

  for(int x = 0, y = m - 1; x < y; ++x, --y){
    swap(dp[x], dp[y]);
    dp[x] = (MOD + s - dp[x]) % MOD;
    dp[y] = (MOD + s - dp[y]) % MOD;
  }

  ll ans = 0;
  for(int mask = (1 << n) - 1; mask != 0; --mask){
    ll ansx = 1ll * __builtin_popcount(mask) * t[mask] * dp[mask];
    ans ^= ansx;
  }

  printf("%lld\n", ans);

  return 0;
}