#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 17
#define M (N * N)
#define B 10
#define INF 1E9

int a[N][N], d[M][M], dp[(1 << B)][M];

int GetIndex(int n, int x, int y){
  return n * x + y;
}

int Solve(){
  int n;
  scanf("%d", &n);

  for(int x = 0; x < n; ++x){
    for(int y = 0; y < n; ++y){
      scanf("%d", &a[x][y]);
    }
  }

  int m = n * n;
  for(int i = 0; i < m; ++i){
    for(int j = 0; j < m; ++j){
      d[i][j] = INF;
    }
    d[i][i] = 0;
  }

  for(int x = 0; x < n; ++x){
    for(int y = 1; y < n; ++y){
      int i = GetIndex(n, x, y - 1);
      int j = GetIndex(n, x, y);
      d[i][j] = d[j][i] = abs(a[x][y] - a[x][y - 1]);
    }
  }

  for(int y = 0; y < n; ++y){
    for(int x = 1; x < n; ++x){
      int i = GetIndex(n, x - 1, y);
      int j = GetIndex(n, x, y);
      d[i][j] = d[j][i] = abs(a[x][y] - a[x - 1][y]);
    }
  }

  for(int k = 0; k < m; ++k){
    for(int i = 0; i < m; ++i){
      for(int j = 0; j < m; ++j){
        d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
      }
    }
  }

  int b;
  scanf("%d", &b);

  for(int mask = 1; mask < (1 << b); ++mask){
    for(int i = 0; i < m; ++i){
      dp[mask][i] = INF;
    }
  }

  for(int k = 0; k < b; ++k){
    int x, y;
    scanf("%d%d", &x, &y);

    int i = GetIndex(n, x, y);
    dp[(1 << k)][i] = 0;
  }

  for(int mask = 0; mask < (1 << b); ++mask){
    for(int i = 0; i < m; ++i){
      int ans = INF;
      for(int smask = mask; smask != 0; smask = ((smask - 1) & mask)){
        ans = min(ans, dp[smask][i] + dp[mask ^ smask][i]);
      }

      for(int j = 0; j < m; ++j){
        dp[mask][j] = min(dp[mask][j], ans + d[i][j]);
      }
    }
  }

  int ans = 0;
  for(int mask = 0; mask < (1 << b); ++mask){
    int ansx = INF;
    for(int i = 0; i < m; ++i){
      ansx = min(ansx, dp[mask][i]);
    }
    ans += ansx;
  }

  return ans;
}

int main(){
  int t;
  scanf("%d", &t);
  while(t--){
    printf("%d\n", Solve());
  }
  return 0;
}