#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 200001

vector< vector<int> > adj(N), block_adj(N);
int dp[N], diameter[N], block_no[N], visited[N], color[N], total_blocks;

void Block_DFS(int i){
  visited[i] = 1;

  for(int j = 0; j < adj[i].size(); j++){
    int k = adj[i][j];

    if(visited[k] == 1)
      continue;

    if(color[i] != color[k]){
      block_no[k] = ++total_blocks;
      block_adj[block_no[i]].PB(block_no[k]);
      block_adj[block_no[k]].PB(block_no[i]);
    }
    else
      block_no[k] = block_no[i];

    Block_DFS(k);
  }
}

void DFS(int i){
  visited[i] = 1;
  dp[i] = 1;

  for(int j = 0; j < block_adj[i].size(); j++){
    int k = block_adj[i][j];

    if(visited[k] == 1)
      continue;

    DFS(k);

    diameter[i] = max(diameter[i], diameter[k]);
    diameter[i] = max(diameter[i], dp[i] + dp[k] - 1);
    dp[i] = max(dp[i], 1 + dp[k]);
  }
}

int main(){
  int n, m, i, j, k;

  scanf("%d", &n);

  for(i = 1; i <= n; i++)
    scanf("%d", &color[i]);

  m = n - 1;

  while(m--){
    scanf("%d%d", &i, &j);
    adj[i].PB(j);
    adj[j].PB(i);
  }

  Block_DFS(1);

  for(i = 0; i <= n; i++)
    visited[i] = 0;

  DFS(0);

  printf("%d\n", (diameter[0] + 1) / 2);

  return 0;
}
