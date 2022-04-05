#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 1001

int a[N][2], dp[N][2];

int main(){
  int n;
  scanf("%d", &n);

  for(int i = 1; i <= n; ++i){
    scanf("%d%d", &a[i][0], &a[i][1]);
  }

  for(int i = 1; i <= n; ++i){
    for(int x = 0; x < 2; ++x){
      int ans = 0;
      for(int y = 0; y < 2; ++y){
        int ansx = dp[i - 1][y] + a[i][x];
        if(i != 1){
          ansx += abs(a[i - 1][1 - y] - a[i][1 - x]);
        }
        ans = max(ans, ansx);
      }
      dp[i][x] = ans;
    }
  }

  printf("%d\n", max(dp[n][0], dp[n][1]));
  
  return 0;
}