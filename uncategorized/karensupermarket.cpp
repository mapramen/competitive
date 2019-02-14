#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 5001
#define B 2

vector< vector<int> > adj(N);
int c[N], d[N], subtreeSize[N], dp[N][N][B], inf = 1000000007;

void DFS(int i){
  int n = 1;
  dp[i][0][0] = 0;
  dp[i][1][0] = c[i];
  dp[i][1][1] = c[i] - d[i];

  for(auto k : adj[i]){
    DFS(k);
    int m = subtreeSize[k];

    for(int x = n; x > -1; x--){
      for(int y = 0; y <= m; y++){
        int z = x + y;
        dp[i][z][1] = min(dp[i][z][1], dp[i][x][1] + min(dp[k][y][1], dp[k][y][0]));
        dp[i][z][0] = min(dp[i][z][0], dp[i][x][0] + dp[k][y][0]);
      }
    }

    n += m;
  }

  subtreeSize[i] = n;
}

int main(){
  int n, b, ans = 0;

  scanf("%d%d", &n, &b);
  scanf("%d%d", &c[1], &d[1]);

  for(int i = 2; i <= n; i++){
    int j;
    scanf("%d%d%d", &c[i], &d[i], &j);
    adj[j].PB(i);
  }

  for(int i = 1; i <= n; i++)
    for(int j = 0; j <= n; j++)
      for(int x = 0; x < B; x++)
        dp[i][j][x] = inf;

  DFS(1);

  for(int i = 1, j = 1; j <= n; j++){
    for(int x = 0; x < B; x++){
      if(dp[i][j][x] <= b)
        ans = j;
    }
  }

  printf("%d\n", ans);

  return 0;
}
