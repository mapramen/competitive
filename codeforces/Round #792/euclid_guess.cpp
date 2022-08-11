#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>

class HopcroftKarpMaximumMatching {
  public:
  vector<pii> GetMaximumMatching(vector<vector<int>>& adj, vector<int>& U, vector<int>& V){
    Initialize(adj);

    for(auto u : U){
      match[u] = n;
    }
    
    for(auto v : V){
      match[v] = n;
    }
    
    for(ResetVisited(); BFS(adj, U); ResetVisited()){
      for(auto u : U){
        if(match[u] == n){
          DFS(adj, u);
        }
      }
    }

    vector<pii> matching;
    for(int u: U){
      if(match[u] != n){
        matching.push_back({u, match[u]});
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

void AddAns(vector<int>& a, vector<bool>& visited, vector<pii>& ans, int i, int j){
  visited[i] = true, visited[j] = true;
  ans.push_back({2 * a[i] + a[j], a[i] + a[j]});
}

int main(){
  int n, m;
  scanf("%d%d", &n, &m);

  vector<int> a, U, V;
  for(int i = 0; i < n; ++i){
    int x;
    scanf("%d", &x);

    if(3ll * x > m){
      U.push_back(i);
    }
    else{
      V.push_back(i);
    }

    a.push_back(x);
  }

  vector<vector<int>> adj(n);
  for(int i: U){
    for(int j: V){
      if(2ll * a[i] + a[j] <= m && a[i] % a[j] == 0){
        adj[i].push_back(j);
      }
    }
  }

  vector<pii> matching = HopcroftKarpMaximumMatching().GetMaximumMatching(adj, U, V);

  if(matching.size() != U.size()){
    printf("-1\n");
    return 0;
  }

  vector<bool> visited(n);
  vector<pii> ans;

  for(auto [i, j]: matching){
    AddAns(a, visited, ans, i, j);
  }

  for(int i = 0; i < n; ++i){
    if(visited[i]){
      continue;
    }
    AddAns(a, visited, ans, i, i);
  }

  printf("%lu\n", ans.size());
  for(auto [x, y]: ans){
    printf("%d %d\n", x, y);
  }

  return 0;
}