#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 502

int a[N][N], dp[N][N], inf = 1e6;

int Solve(){
  int n, m;
  scanf("%d%d", &n, &m);

  for(int i = 1; i <= n; ++i){
    for(int j = 1; j <= m; ++j){
      scanf("%d", &a[i][j]);
    }
  }

  for(int i = 1; i <= n; ++i){
    dp[i][m + 1] = -inf;
  }

  for(int j = 1; j <= m; ++j){
    dp[n + 1][j] = -inf;
  }

  dp[n][m + 1] = 0, dp[n + 1][m] = 0;
  for(int i = n; i != 0; --i){
    for(int j = m; j != 0; --j){
      dp[i][j] = min(0, a[i][j] + max(dp[i][j + 1], dp[i + 1][j]));
    }
  }

  return 1 - dp[1][1];
}

int main(){
  int t;
  scanf("%d", &t);
  while(t--){
    printf("%d\n", Solve());
  }
  return 0;
}