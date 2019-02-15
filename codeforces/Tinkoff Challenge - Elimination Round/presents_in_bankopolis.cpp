#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 82

vector< vector< pii > > adj(N);
int dp[N][N][N][2], pre[N][N], suf[N][N], inf = INT_MAX / 2;

int main(){
  int n, k, m, ans = inf;

  scanf("%d%d%d", &n, &k, &m);

  while(m--){
    int u, v, c;
    scanf("%d%d%d", &u, &v, &c);
    adj[u].PB(MP(v, c));
  }

  for(int kx = 2; kx <= k; kx++)
    for(int i = 0; i <= n + 1; i++)
      for(int j = 0; j <= n + 1; j++)
        dp[kx][i][j][0] = dp[kx][i][j][1] = inf;

  for(int kx = 1; kx < k; kx++){
    for(int u = 1; u <= n; u++){
      for(auto p : adj[u]){
        int v, c;
        tie(v, c) = p;
        if(u < v)
          dp[kx + 1][v][n + 1][0] = min(dp[kx + 1][v][n + 1][0], dp[kx][u][n + 1][0] + c);

        if(v < u)
          dp[kx + 1][0][v][1] = min(dp[kx + 1][0][v][1], dp[kx][0][u][1] + c);
      }
    }
  }

  for(int kx = 1; kx < k; kx++){
    for(int i = 0; i <= n + 1; i++){
      for(int j = i; j <= n + 1; j++){
        for(int x = 0; x < 2; x++){
          int u = (x == 0) ? i : j;
          for(auto p : adj[u]){
            int v, c;
            tie(v, c) = p;
            if(i < v && v < j){
              dp[kx + 1][i][v][1] = min(dp[kx + 1][i][v][1], dp[kx][i][j][x] + c);
              dp[kx + 1][v][j][0] = min(dp[kx + 1][v][j][0], dp[kx][i][j][x] + c);
            }
          }
        }
      }
    }
  }

  for(int i = 0; i <= n + 1; i++)
    for(int j = i; j <= n + 1; j++)
      for(int x = 0; x < 2; x++)
        ans = min(ans, dp[k][i][j][x]);

  if(ans == inf)
    ans = -1;

  printf("%d\n", ans);

  return 0;
}
