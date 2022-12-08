#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 51
#define M 1001

int dp[N][M];

void Initialize(){
  for(int j = 0; j < M; ++j){
    dp[0][j] = 1;
  }

  for(int i = 1; i < N; ++i){
    dp[i][0] = 1;
    for(int j = 1; j < M; ++j){
      dp[i][j] = min(M, dp[i][j - 1] + dp[i - 1][j - 1]);
    }
  }
}

int Solve(){
  int p, n, m;
  scanf("%d%d%d", &p, &n, &m);
  return lower_bound(dp[n], dp[n] + M, m) - dp[n];
}

int main(){
  Initialize();

  int t;
  scanf("%d", &t);
  
  for(int k = 1; k <= t; ++k){
    printf("%d %d\n", k, Solve());
  }
  
  return 0;
}