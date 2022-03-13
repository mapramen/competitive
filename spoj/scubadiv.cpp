#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 22
#define M 80

int dp[N][M];

int Solve(){
  int n, m, k;
  scanf("%d%d%d", &n, &m, &k);

  for(int i = 0; i <= n; ++i){
    for(int j = 0; j <= m; ++j){
      dp[i][j] = INT_MAX;
    }
  }

  dp[0][0] = 0;
  while(k--){
    int x, y, w;
    scanf("%d%d%d", &x, &y, &w);
    x = min(x, n), y = min(y, m);

    for(int i = n; i != -1; --i){
      for(int j = m; j != -1; --j){
        if(dp[i][j] == INT_MAX){
          continue;
        }

        int ni = min(n, i + x), nj = min(m, j + y);
        dp[ni][nj] = min(dp[ni][nj], dp[i][j] + w);
      }
    }
  }

  return dp[n][m];
}

int main(){
  int t;
  scanf("%d", &t);
  while(t--){
    printf("%d\n", Solve());
  }
  return 0;
}