#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 4001
#define MOD 1000000007
#define INV2 500000004

int a[N], dp[N][N];

int Solve(){
  int n, q;
  scanf("%d%d", &n, &q);

  for(int i = 1; i <= n; ++i){
    scanf("%d", &a[i]);
  }

  for(int i = 1; i <= n; ++i){
    for(int j = 1; j <= n; ++j){
      dp[i][j] = max(0, a[j] - a[i]) % MOD;
    }
  }

  int m = 1;
  while(q--){
    int i, j;
    scanf("%d%d", &i, &j);

    int z = (1ll * INV2 * (dp[i][j] + dp[j][i])) % MOD;
    dp[i][j] = z, dp[j][i] = z;
    
    for(int k = 1; k <= n; ++k){
      if(k == i || k == j){
        continue;
      }

      int x = (1ll * INV2 * (dp[k][i] + dp[k][j])) % MOD;
      int y = (1ll * INV2 * (dp[i][k] + dp[j][k])) % MOD;

      dp[k][i] = x, dp[k][j] = x;
      dp[i][k] = y, dp[j][k] = y;
    }

    m = (2 * m) % MOD;
  }

  ll ans = 0;
  for(int i = 1; i <= n; ++i){
    for(int j = i + 1; j <= n; ++j){
      ans = (ans + 1ll * (j - i) * dp[i][j]) % MOD;
    }
  }

  return (m * ans) % MOD;
}

int main(){
  int t;
  scanf("%d", &t);

  while(t--){
    printf("%d\n", Solve());
  }

  return 0;
}