#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 2001

vector<vector<int>> adj(N);
bool visited[N];
int color[N];

bool DFS(int i, int c){
  if(visited[i]){
    return color[i] == c;
  }

  visited[i] = true;
  color[i] = c;

  bool ans = true;
  for(int j: adj[i]){
    ans = ans && DFS(j, 1 - c);
  }

  return ans;
}

bool Solve(){
  int n, m;
  scanf("%d%d", &n, &m);

  for(int i = 1; i <= n; ++i){
    visited[i] = false;
    color[i] = 0;
    adj[i].clear();
  }

  while(m--){
    int i, j;
    scanf("%d%d", &i, &j);
    adj[i].push_back(j);
    adj[j].push_back(i);
  }

  bool ans = true;
  for(int i = 1; i <= n; ++i){
    ans = ans && DFS(i, color[i]);
  }

  return ans;
}

int main(){
  int t;
  scanf("%d", &t);
  for(int k = 1; k <= t; ++k){
    printf("Scenario #%d:\n%s bugs found!\n", k, Solve() ? "No suspicious" : "Suspicious");
  }
  return 0;
}