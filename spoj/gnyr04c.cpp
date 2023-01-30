#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 11
#define M 2001

ll dp[N][M];

void Initialize(){
  for(int j = 0; j < M; ++j){
    dp[0][j] = 1;
  }

  for(int i = 1; i < N; ++i){
    for(int j = 1; j < M; ++j){
      dp[i][j] = dp[i - 1][j / 2];
    }

    for(int j = 1; j < M; ++j){
      dp[i][j] += dp[i][j - 1];
    }
  }
}

ll Solve(int n, int m){
  return dp[n][m];
}

int main(){
  Initialize();

  int t;
  scanf("%d", &t);
  
  for(int k = 1; k <= t; ++k){
    int n, m;
    scanf("%d%d", &n, &m);
    printf("Data set %d: %d %d %lld\n", k, n, m, Solve(n, m));
  }
  
  return 0;
}