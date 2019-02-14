#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 2001
#define M 6

int a[N], b[N], dp[N][N][M];

int main(){
  int n, m, k;

  scanf("%d%d%d", &n, &m, &k);

  for(int i = 1; i <= n; ++i)
    scanf("%d", &a[i]);

  for(int i = 1; i <= m; ++i)
    scanf("%d", &b[i]);

  for(int i = 1; i <= n; ++i){
    for(int j = 1; j <= m; ++j){
      for(int x = 0; x <= k; ++x){
        if(x)
          dp[i][j][x] = dp[i][j][x - 1];

        if(a[i] == b[j])
          dp[i][j][x] = max(dp[i][j][x], 1 + dp[i - 1][j - 1][x]);

        dp[i][j][x] = max(dp[i][j][x], max(dp[i][j - 1][x], dp[i - 1][j][x]));

        if(x){
          dp[i][j][x] = max(dp[i][j][x], 1 + max(dp[i - 1][j][x - 1], dp[i][j - 1][x - 1]));
        }
      }
    }
  }

  int ans = 0;
  for(int x = 0; x <= k; ++x)
    ans = max(ans, dp[n][m][x]);

  printf("%d\n", ans);

  return 0;
}
