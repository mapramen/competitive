#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define pil pair<int,ll>
#define N 200001

vector<vector<int>> adj(N);
pil dp[2][N];
int w[N];

void DFS(int i, int p){
  int take_i_count = 1, skip_i_count = 0;
  ll take_i_sum = -(int)adj[i].size(), skip_i_sum = -1;

  for(int j: adj[i]){
    if(j == p){
      continue;
    }
    
    DFS(j, i);

    take_i_count += dp[0][j].first, take_i_sum += dp[0][j].second;

    pil q = max(dp[0][j], dp[1][j]);
    skip_i_count += q.first, skip_i_sum += q.second;
  }

  dp[0][i] = {skip_i_count, skip_i_sum};
  dp[1][i] = {take_i_count, take_i_sum};
}

void AssignDFS(int i, int p, bool take){
  w[i] = take ? adj[i].size() : 1;

  for(int j: adj[i]){
    if(j == p){
      continue;
    }

    if(take){
      AssignDFS(j, i, false);
    }
    else{
      AssignDFS(j, i, dp[1][j] >= dp[0][j]);
    }
  }
}

int main(){
  int n;
  scanf("%d", &n);

  if(n == 2){
    printf("2 2\n1 1\n");
    return 0;
  }

  for(int x = 1; x < n; ++x){
    int i, j;
    scanf("%d%d", &i, &j);
    adj[i].push_back(j);
    adj[j].push_back(i);
  }

  for(int i = 1; i <= n; ++i){
    w[i] = 1;
  }

  DFS(1, 0);
  AssignDFS(1, 0, dp[1][1] >= dp[0][1]);

  auto [ans, sum] = max(dp[0][1], dp[1][1]);
  printf("%d %lld\n", ans, -sum);
  for(int i = 1; i <= n; ++i){
    printf("%d ", w[i]);
  }
  printf("\n");

  return 0;
}