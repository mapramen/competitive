#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 200001

vector<vector<int>> adj(N);
int in_degree[N], out_degree[N], dp[N];
bool visited[N];

int DFS(int i){
  if(visited[i]){
    return dp[i];
  }

  visited[i] = true;
  if(out_degree[i] < 2){
    dp[i] = 1;
    return dp[i];
  }

  int ans = 0;
  for(int j: adj[i]){
    if(in_degree[j] < 2){
      continue;
    }
    ans = max(ans, DFS(j));
  }

  dp[i] = ++ans;
  return ans;
}

int main(){
  int n, m;
  scanf("%d%d", &n, &m);

  while(m--){
    int i, j;
    scanf("%d%d", &i, &j);
    adj[i].push_back(j);
    ++in_degree[j], ++out_degree[i];
  }

  int ans = 0;
  for(int i = 1; i <= n; ++i){
    ans = max(ans, DFS(i));
  }

  printf("%d\n", ans);

  return 0;
}