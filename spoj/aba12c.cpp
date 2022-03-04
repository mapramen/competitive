#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 101
#define INF 1E9

int dp[N][N];

int Solve(){
  int n, m;
  scanf("%d%d", &n, &m);

  for(int i = 0; i <= n; ++i){
    for(int j = 0; j <= m; ++j){
      dp[i][j] = INF;
    }
  }

  dp[0][0] = 0;
  for(int k = 1; k <= m; ++k){
    int cost;
    scanf("%d", &cost);

    if(cost == -1){
      continue;
    }

    for(int i = 1; i <= n; ++i){
      for(int j = k; j <= m; ++j){
        dp[i][j] = min(dp[i][j], dp[i - 1][j - k] + cost);
      }
    }
  }

  int ans = INF;
  for(int i = 0; i <= n; ++i){
    ans = min(ans, dp[i][m]);
  }

  return ans == INF ? -1 : ans;
}

int main(){
  int t;
  scanf("%d", &t);
  while(t--){
    printf("%d\n", Solve());
  }
  return 0;
}