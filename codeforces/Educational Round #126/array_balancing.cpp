#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 26

int a[N], b[N];
ll dp[N][2];

ll Solve(){
  int n;
  scanf("%d", &n);

  for(int i = 1; i <= n; ++i){
    scanf("%d", &a[i]);
  }

  for(int i = 1; i <= n; ++i){
    scanf("%d", &b[i]);
  }

  for(int i = 2; i <= n; ++i){
    for(int y = 0; y < 2; ++y){
      int y1 = y == 0 ? a[i] : b[i];
      int y2 = y == 0 ? b[i] : a[i];

      ll ans = LLONG_MAX;

      for(int x = 0; x < 2; ++x){
        int x1 = x == 0 ? a[i - 1] : b[i - 1];
        int x2 = x == 0 ? b[i - 1] : a[i - 1];

        ll ansx = dp[i - 1][x] + abs(y1 - x1) + abs(y2 - x2);
        ans = min(ans, ansx);
      }

      dp[i][y] = ans;
    }
  }

  return min(dp[n][0], dp[n][1]);
}

int main(){
  int t;
  scanf("%d", &t);
  while(t--){
    printf("%lld\n", Solve());
  }
  return 0;
}