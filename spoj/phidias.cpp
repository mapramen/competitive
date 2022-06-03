#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 601

int dp[N][N];

int Solve(){
  int w, h, n;
  scanf("%d%d%d", &w, &h, &n);

  for(int i = 1; i <= w; ++i){
    for(int j = 1; j <= h; ++j){
      dp[i][j] = i * j;
    }
  }

  while(n--){
    int i, j;
    scanf("%d%d", &i, &j);
    dp[i][j] = 0;
  }

  for(int i = 1; i <= w; ++i){
    for(int j = 1; j <= h; ++j){
      int ans = dp[i][j];
      
      for(int x = 1; 2 * x <= i; ++x){
        ans = min(ans, dp[x][j] + dp[i - x][j]);
      }

      for(int y = 1; 2 * y <= j; ++y){
        ans = min(ans, dp[i][y] + dp[i][j - y]);
      }

      dp[i][j] = ans;
    }
  }

  return dp[w][h];
}

int main(){
  int t;
  scanf("%d", &t);
  while(t--){
    printf("%d\n", Solve());
  }
  return 0;
}