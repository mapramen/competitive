#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define M 11
#define N 100001
#define MOD 1000000007

vector< vector<int> > adj(N);
int n, k, m, x;
ll dp[N][3][M], c[3][M];

void DFS(int u, int p){
  dp[u][0][0] = k - 1;
  dp[u][1][1] = 1;
  dp[u][2][0] = m - k;

  for(auto v : adj[u]){
    if(v == p)
      continue;

    DFS(v, u);

    for(int i = 0; i < 3; ++i)
      for(int j = 0; j <= x; ++j)
        c[i][j] = 0;

    for(int i = x; i > -1; --i){
      for(int j = 0; j <= i; ++j){
        c[0][i] = (c[0][i] + dp[u][0][i - j] * (dp[v][0][j] + dp[v][1][j] + dp[v][2][j])) % MOD;
        c[1][i] = (c[1][i] + dp[u][1][i - j] * dp[v][0][j]) % MOD;
        c[2][i] = (c[2][i] + dp[u][2][i - j] * (dp[v][0][j] + dp[v][2][j])) % MOD;
      }
    }

    for(int i = 0; i < 3; ++i)
      for(int j = 0; j <= x; ++j)
        dp[u][i][j] = c[i][j];
  }
}

int main(){
  scanf("%d%d", &n, &m);

  for(int x = 1; x < n; ++x){
    int u, v;
    scanf("%d%d", &u, &v);
    adj[u].PB(v);
    adj[v].PB(u);
  }

  scanf("%d%d", &k, &x);

  DFS(1, 0);

  ll ans = 0;
  for(int i = 0; i < 3; ++i)
    for(int j = 0; j <= x; ++j)
      ans = (ans + dp[1][i][j]) % MOD;

  printf("%lld\n", ans);

  return 0;
}
