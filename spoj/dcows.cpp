#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 5001

int a[N], b[N];
ll dp[N][N];

int main(){
  int n, m;
  scanf("%d%d", &n, &m);

  for(int i = 1; i <= n; ++i){
    scanf("%d", &a[i]);
  }

  for(int j = 1; j <= m; ++j){
    scanf("%d", &b[j]);
  }

  sort(a + 1, a + n + 1);
  sort(b + 1, b + m + 1);

  for(int i = 1; i <= n; ++i){
    dp[i][0] = LLONG_MAX / 2;
    for(int j = 1; j <= m; ++j){
      dp[i][j] = min(dp[i][j - 1], dp[i - 1][j - 1] + abs(a[i] - b[j]));
    }
  }

  printf("%lld\n", dp[n][m]);
  
  return 0;
}