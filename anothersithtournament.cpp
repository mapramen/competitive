#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define B 18

double p[B][B], dp[B][(1 << B)];

int main(){
  int n;
  double ans = 0;

  scanf("%d", &n);
  for(int i = 0; i < n; ++i)
    for(int j = 0; j < n; ++j)
      scanf("%lf", &p[i][j]);

  dp[0][(1 << n) - 1] = 1;

  for(int x = (1 << n) - 1; x > 0; --x){
    for(int i = 0; i < n; i++){
      if((x & (1 << i)) == 0)
        continue;
      for(int j = 0; j < n; j++){
        if((x & (1 << j)) > 0)
          continue;
        int y = (x | (1 << j));
        dp[i][x] = max(dp[i][x], p[i][j] * dp[i][y] + p[j][i] * dp[j][y]);
      }
    }
  }

  for(int i = 0; i < n; i++){
    // printf("%d %.15lf\n", i, dp[i][(1 << i)]);
    ans = max(ans, dp[i][(1 << i)]);
  }

  printf("%.15lf\n", ans);

  return 0;
}
