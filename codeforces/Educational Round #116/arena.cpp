#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 501
#define MOD 998244353

ll c[N][N], p[N][N], dp[N][N];

int main(){
  int n, m;
  cin >> n >> m;

  for(int i = 0; i <= n; ++i){
    c[i][0] = 1;
    for(int j = 1; j <= i; ++j){
      c[i][j] = (c[i - 1][j - 1] + c[i - 1][j]) % MOD;
    }
  }

  for(int i = 1; i <= m; ++i){
    ll x = 1;
    for(int j = 0; j <= n; ++j){
      p[i][j] = x;
      x = (x * i) % MOD;
    } 
  }

  for(int j = 0; j <= m; ++j){
    dp[0][j] = 1;
  }

  for(int i = 1; i <= n; ++i){
    dp[i][0] = 1;
    
    for(int j = 1; j < i; ++j){
      dp[i][j] = p[j][i];
    }

    for(int j = i; j <= m; ++j){
      ll ans = 0;
      for(int x = 0; x <= i; ++x){
        ll ansx = dp[i - x][max(0, j - (i - 1))];
        ansx = (ansx * c[i][x]) % MOD;
        ansx = (ansx * p[i - 1][x]) % MOD;
        ans = (ans + ansx) % MOD;
      }
      dp[i][j] = ans;
    }
  }

  printf("%lld\n", dp[n][m]);

  return 0;
}