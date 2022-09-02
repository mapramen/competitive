#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>

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

vector<pii> ReadCoordinates(int n){
  vector<pii> a(n);
  for(pii& p: a){
    scanf("%d%d", &p.first, &p.second);
  }
  return a;
}

bool IsWithinTime(int s, int t, pii a, pii b){
  return 200ll * (abs(a.first - b.first) + abs(a.second - b.second)) <= s * t;
}

int Solve(){
  int n, m, s, t;
  scanf("%d%d%d%d", &n, &m, &s, &t);

  vector<pii> a = ReadCoordinates(n);
  vector<pii> b = ReadCoordinates(m);

  vector<vector<int>> adj(n + m);
  for(int i = 0; i < n; ++i){
    for(int j = 0; j < m; ++j){
      if(IsWithinTime(s, t, a[i], b[j])){
        adj[i].push_back(n + j);
      }
    }
  }

  vector<int> U(n);
  vector<int> V(m);

  iota(U.begin(), U.end(), 0);
  iota(V.begin(), V.end(), n);

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