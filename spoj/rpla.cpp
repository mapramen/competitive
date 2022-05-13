#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 1001

vector<vector<int>> adj(N), rank_to_employees(N);
vector<int> topological_order;
int dp[N];
bool visited[N];

void Reset(int n){
  for(int i = 0; i <= n; ++i){
    visited[i] = false;
    adj[i].clear();
    rank_to_employees[i].clear();
  }
  topological_order.clear();
}

void VisitDFS(int i){
  if(visited[i]){
    return;
  }
  
  visited[i] = true;
  for(int j: adj[i]){
    VisitDFS(j);
  }

  topological_order.push_back(i);
}

void Solve(){
  int n, m;
  scanf("%d%d", &n, &m);

  Reset(n);

  while(m--){
    int i, j;
    scanf("%d%d", &i, &j);
    adj[i].push_back(j);
  }

  for(int i = 0; i < n; ++i){
    VisitDFS(i);
  }

  for(int i: topological_order){
    int rank = 0;
    for(int j: adj[i]){
      rank = max(rank, dp[j]);
    }
    dp[i] = ++rank;
  }

  for(int i = 0; i < n; ++i){
    rank_to_employees[dp[i]].push_back(i);
  }

  for(int rank = 1; rank <= n; ++rank){
    for(int i: rank_to_employees[rank]){
      printf("%d %d\n", rank, i);
    }
  }
}

int main(){
  int t;
  scanf("%d", &t);
  for(int k = 1; k <= t; ++k){
    printf("Scenario #%d:\n", k);
    Solve();
  }
  return 0;
}