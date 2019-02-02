#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 100001
#define B 2

vector< vector<int> > adj(N);
ll dp[N][B][B][B];

void DFS(int i, int parent){
  if(adj[i].size() == 1 && parent != 0){
    for(int p1 = 0; p1 < B; p1++)
      for(int p2 = 0; p2 < B; p2++)
        if(p1 + p2 > 0)
          dp[i][1][p1][p2] = 1;
    return ;
  }

  for(int k : adj[i]){
    if(k == parent)
      continue;
    DFS(k, i);
  }

  for(int p1 = 0; p1 < B; p1++){
    for(int p2 = 0; p2 < B; p2++){
      dp[i][1][p1][p2] = 1;
      for(auto k : adj[i]){
        if(k == parent)
          continue;
        dp[i][1][p1][p2] += min(dp[k][0][1][p1], dp[k][1][1][p1]);
      }
    }
  }

  ll ans = 0;
  ll minx = N;
  for(auto k : adj[i]){
    if(k == parent)
      continue;
    ll ansx = min(dp[k][0][0][1], dp[k][1][0][1]);
    ans += ansx;
    minx = min(minx, dp[k][1][0][1] - ansx);
  }
  dp[i][0][1][0] = dp[i][0][1][1] = ans + minx;

  ans = 0;
  ll min1 = N, min2 = N;
  for(auto k : adj[i]){
    if(k == parent)
      continue;
    ll ansx = min(dp[k][0][0][0], dp[k][1][0][0]);
    ans += ansx;
    minx = dp[k][1][0][0] - ansx;
    if(minx <= min1)
      min2 = min1, min1 = minx;
    else
      min2 = min(min2, minx);
  }
  dp[i][0][0][0] = dp[i][0][0][1] = ans + min1 + min2;

  for(int p = 0; p < B; p++)
    for(int p1 = 0; p1 < B; p1++)
      for(int p2 = 0; p2 < B; p2++)
        dp[i][p][p1][p2] = min(dp[i][p][p1][p2], 1ll * N);
}

int main(){
  int t;
  scanf("%d", &t);
  while(t--){
    int n, ans;

    scanf("%d", &n);

    for(int i = 1; i <= n; i++)
      adj[i].clear();

    for(int x = 1; x < n; x++){
      int i, j;
      scanf("%d%d", &i, &j);
      adj[i].PB(j);
      adj[j].PB(i);
    }

    for(int i = 1; i <= n; i++)
      for(int p = 0; p < B; p++)
        for(int p1 = 0; p1 < B; p1++)
          for(int p2 = 0; p2 < B; p2++)
            dp[i][p][p1][p2] = N;

    DFS(1, 0);
    ans = min(dp[1][1][0][0], dp[1][0][0][0]);

    if(ans > n || n == 1)
      ans = -1;

    printf("%d\n", ans);
  }

  return 0;
}
