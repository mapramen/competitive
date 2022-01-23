#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 501

int d[N], a[N];
int dp[N][N];

int main(){
  int n, l, m;
  scanf("%d%d%d", &n, &l, &m);

  for(int i = 0; i < n; ++i){
    scanf("%d", &d[i]);
  }

  for(int i = 0; i < n; ++i){
    scanf("%d", &a[i]);
  }

  d[n] = l;
  for(int i = 0; i <= n; ++i){
    for(int k = 0; k <= n; ++k){
      dp[i][k] = 1E9;
    }
  }

  dp[0][0] = 0;
  for(int i = 0; i <= n; ++i){
    for(int k = 0; k < n; ++k){
      for(int j = i + 1; j <= n; ++j){
        dp[j][k + 1] = min(dp[j][k + 1], dp[i][k] + a[i] * (d[j] - d[i]));
      }
    }
  }

  int ans = INT_MAX;
  for(int k = n - m; k <= n; ++k){
    ans = min(ans, dp[n][k]);
  }

  printf("%d\n", ans);

  return 0;
}