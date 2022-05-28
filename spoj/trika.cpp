#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 21

int a[N][N];

int main(){
  int n, m, x, y;
  scanf("%d%d%d%d", &n, &m, &x, &y);

  for(int i = 1; i <= n; ++i){
    for(int j = 1; j <= m; ++j){
      scanf("%d", &a[i][j]);
    }
  }

  int ans = 2 * a[x][y];

  for(int i = n; i != 0; --i){
    for(int j = m; j != 0; --j){
      int dp = i == n && j == m ? 0 : INT_MAX;
      if(j != m){
        dp = min(dp, a[i][j + 1]);
      }

      if(i != n){
        dp = min(dp, a[i + 1][j]);
      }

      a[i][j] += dp;
    }
  }

  ans -= a[x][y];

  if(ans < 0){
    printf("N\n");
  }
  else{
    printf("Y %d\n", ans);
  }

  return 0;
}