#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>

class HopcroftKarpMaximumMatching {
  public:
  vector<pii> GetMinimumVertexCoverWithMatching(vector<vector<int>>& adj, vector<int>& U, vector<int>& V){
    GetMaximumMatching(adj, U, V);

    vector<pii> min_vertex_cover;

    for(auto u : U){
      if(match[u] != n && visited[u] == 0){
        min_vertex_cover.push_back({u, match[u]});
      }
    }

    for(auto v : V){
      if(match[v] != n && visited[v] == 1){
        min_vertex_cover.push_back({v, match[v]});
      }
    }

    return min_vertex_cover;
  }

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

int main(){
  int n1, n2, m, q;
  scanf("%d%d%d%d", &n1, &n2, &m, &q);

  vector<vector<int>> adj(n1 + n2);
  map<pii,int> edges;

  for(int e = 1; e <= m; ++e){
    int u, v;
    scanf("%d%d", &u, &v);
    --u, --v;

    v += n1;

    adj[u].push_back(v);
    edges[{u, v}] = e;
  }

  vector<int> U(n1), V(n2);
  iota(U.begin(), U.end(), 0);
  iota(V.begin(), V.end(), n1);

  vector<pii> min_vertex_cover = HopcroftKarpMaximumMatching().GetMinimumVertexCoverWithMatching(adj, U, V);

  ll max_matching_edge_no_sum = 0;
  vector<int> max_matching_edge_nos;
  
  for(auto [u, v]: min_vertex_cover){
    int e = edges[{min(u, v), max(u, v)}];

    max_matching_edge_no_sum += e;
    max_matching_edge_nos.push_back(e);
  }

  while(q--){
    int t;
    scanf("%d", &t);

    if(t == 1){
      int i = min_vertex_cover.back().first;
      min_vertex_cover.pop_back();

      max_matching_edge_no_sum -= max_matching_edge_nos.back();
      max_matching_edge_nos.pop_back();

      i = i < n1 ? 1 + i : -(i - n1 + 1);
      printf("%d\n%d\n%lld\n", 1, i, max_matching_edge_no_sum);
    }
    else{
      printf("%lu\n", max_matching_edge_nos.size());
      for(int e: max_matching_edge_nos){
        printf("%d ", e);
      }
      printf("\n");
    }

    fflush(stdout);
  }

  return 0;
}