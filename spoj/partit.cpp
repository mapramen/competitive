#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 11
#define M 221

ll dp[N][M][M];

void Initialize(){
  for(int j = 0; j < M; ++j){
    dp[0][0][j] = 1;
  }

  for(int k = 1; k < N; ++k){
    for(int i = 1; i < M; ++i){
      for(int j = 1; j <= i; ++j){
        dp[k][i][j] = dp[k - 1][i - j][j];
      }

      for(int j = M - 2; j != 0; --j){
        dp[k][i][j] += dp[k][i][j + 1];
      }
    }
  }

  for(int k = 1; k < N; ++k){
    for(int i = 1; i < M; ++i){
      for(int j = 1; j < M - 1; ++j){
        dp[k][i][j] -= dp[k][i][j + 1];
      }
    }
  }
}

void Solve(){
  int m, n;
  ll k;
  scanf("%d%d%lld", &m, &n, &k);

  for(int j = 1; n != 0; --n){
    for( ; dp[n][m][j] < k; ++j){
      k -= dp[n][m][j];
    }
    printf("%d ", j);
    m -= j;
  }
  printf("\n");
}

int main(){
  Initialize();

  int t;
  scanf("%d", &t);
  
  while(t--){
    Solve();
  }
  
  return 0;
}