#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 120

class HopcroftKarpMaximumMatching {
  public:
  int CalculateMaximumMatching(vector<vector<int>>& adj, vector<int>& U, vector<int>& V){
    Initialize(adj);

    for(auto u : U){
      match[u] = n;
    }
    
    for(auto v : V){
      match[v] = n;
    }
    
    int matching = 0;
    for(ResetVisited(); BFS(adj, U); ResetVisited()){
      for(auto u : U){
        if(match[u] == n){
          matching += DFS(adj, u);
        }
      }
    }
    return matching;
  }

  private:
  const int inf = 1E9;
  int n;
  vector<bool> visited;
  vector<int> match;
  vector<int> dis;
  queue<int> Q;

  void Initialize(vector<vector<int>>& adj){
    n = adj.size();

    visited.resize(n + 1);
    match.resize(n + 1);
    dis.resize(n + 1);
  }

  void ResetVisited(){
    for(int i = 0; i <= n; ++i){
      visited[i] = false;
    }
  }

  bool BFS(vector<vector<int>>& adj, vector<int>& U){
    for(int u: U){
      if(match[u] == n){
        dis[u] = 0;
        Q.push(u);
      }
      else{
        dis[u] = inf;
      }
    }

    dis[n] = inf;

    while(!Q.empty()){
      int u = Q.front();
      Q.pop();
      visited[u] = true;
      if(dis[u] < dis[n]){
        for(int v: adj[u]){
          if(dis[match[v]] == inf){
            visited[v] = true;
            dis[match[v]] = 1 + dis[u];
            Q.push(match[v]);
          }
        }
      }
    }

    return (dis[n] != inf);
  }

  bool DFS(vector<vector<int>>& adj, int u){
    if(u == n){
      return true;
    }

    for(int v: adj[u]){
      if(dis[match[v]] == 1 + dis[u]){
        if(DFS(adj, match[v])){
          match[v] = u;
          match[u] = v;
          return true;
        }
      }
    }

    dis[u] = inf;
    return false;
  }
};

int Solve(){
  int m;
  scanf("%d", &m);

  vector<vector<int>> adj(N + N);

  for(int i = 0; i < m; ++i){
    int x, y;
    scanf("%d%d", &x, &y);
    adj[x].push_back(N + y);
  }

  vector<int> U(N), V(N);
  iota(U.begin(), U.end(), 0);
  iota(V.begin(), V.end(), N);

  return HopcroftKarpMaximumMatching().CalculateMaximumMatching(adj, U, V);
}

int main(){
  int t;
  scanf("%d", &t);
  while(t--){
    printf("%d\n", Solve());
  }
  return 0;
}