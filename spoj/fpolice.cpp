#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 101
#define M 251

int risks[N][N], times[N][N];
ll dp[N][M];

void BellmanFord(int n, int m){
  for(int i = 1; i <= n; ++i){
    for(int t = 0; t <= m; ++t){
      if(dp[i][t] == LLONG_MAX){
        continue;
      }

      for(int j = 1; j <= n; ++j){
        int nt = t + times[i][j];
        if(nt > m){
          continue;
        }
        dp[j][nt] = min(dp[j][nt], dp[i][t] + risks[i][j]);
      }
    }
  }
}

void Solve(){
  int n, m;
  scanf("%d%d", &n, &m);

  for(int i = 1; i <= n; ++i){
    for(int j = 1; j <= n; ++j){
      scanf("%d", &times[i][j]);
    }
  }

  for(int i = 1; i <= n; ++i){
    for(int j = 1; j <= n; ++j){
      scanf("%d", &risks[i][j]);
    }
  }

  for(int i = 0; i <= n; ++i){
    for(int t = 0; t <= m; ++t){
      dp[i][t] = LLONG_MAX;
    }
  }

  dp[1][0] = 0;
  for(int k = 1; k <= m; ++k){
    BellmanFord(n, m);
  }

  ll ans_toll = LLONG_MAX;
  int ans_time = -1;

  for(int t = 0; t <= m; ++t){
    if(dp[n][t] < ans_toll){
      ans_toll = dp[n][t], ans_time = t;
    }
  }

  if(ans_time == -1){
    printf("-1\n");
    return;
  }

  printf("%lld %d\n", ans_toll, ans_time);
}

int main(){
  int t;
  scanf("%d", &t);
  while(t--){
    Solve();
  }
  return 0;
}