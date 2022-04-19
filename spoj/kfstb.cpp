#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 10001
#define MOD 1000000007

vector<vector<int>> adj(N);
int in_degrees[N], dp[N];
bool visited[N];
vector<int> topological_order;

void Reset(int n){
  for(int i = 1; i <= n; ++i){
    adj[i].clear();
    visited[i] = false, dp[i] = 0;
  }
  topological_order.clear();
}

void DFS(int i){
  if(visited[i]){
    return;
  }

  visited[i] = true;
  for(int j: adj[i]){
    DFS(j);
  }

  topological_order.push_back(i);
}

int Solve(){
  int n, m, s, t;
  scanf("%d%d%d%d", &n, &m, &s, &t);

  Reset(n);

  while(m--){
    int i, j;
    scanf("%d%d", &i, &j);
    adj[i].push_back(j);
  }

  DFS(1);
  reverse(topological_order.begin(), topological_order.end());

  dp[s] = 1;
  for(int i: topological_order){
    for(int j: adj[i]){
      dp[j] = (dp[j] + dp[i]) % MOD;
    }
  }

  return dp[t];
}

int main(){
  int t;
  scanf("%d", &t);
  while(t--){
    printf("%d\n", Solve());
  }
  return 0;
}