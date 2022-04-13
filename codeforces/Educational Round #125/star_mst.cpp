#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 251
#define MOD 998244353 

int dp[N][N], c[N][N];

int ModularExponentation(int a, int n){
  int ans = 1;
  for( ; n > 0; n /= 2){
    if(n % 2 == 1){
      ans = (1ll * ans * a) % MOD;
    }
    a = (1ll * a * a) % MOD;
  }
  return ans;
}

void Initialise(){
  for(int i = 0; i < N; ++i){
    c[i][0] = 1;
    for(int j = 1; j <= i; ++j){
      c[i][j] = (c[i - 1][j - 1] + c[i - 1][j]) % MOD;
    }
  }
}

int main(){
  int n, m;
  scanf("%d%d", &n, &m);

  Initialise();

  for(int k = 0; k <= m; ++k){
    dp[1][k] = 1;
  }

  for(int i = 2; i <= n; ++i){
    int ans = 0;
    for(int k = 1; k <= m; ++k){
      int a = m - k + 1;
      for(int x = 1; x < i; ++x){
        int b = x * (x - 1) / 2 + x * (i - 1 - x);
        
        int ansx = (1ll * c[i - 1][x] * ModularExponentation(a, b)) % MOD;
        ansx = (1ll * ansx * dp[i - x][k - 1]) % MOD;

        ans = (ans + ansx) % MOD;
      }
      dp[i][k] = ans;
    }
  }

  printf("%d\n", dp[n][m]);

  return 0;
}