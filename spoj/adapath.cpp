#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define B 10

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

vector<pii> moves{{-1, 0}, {0, -1}, {0, 1}, {1, 0}};

int GetIndex(int n, int x, int y){
  return x * n + y;
}

void SortAndDedup(vector<int>& C){
  sort(C.begin(), C.end());
  C.erase(unique(C.begin(), C.end()), C.end());
}

int GetCompressedValue(vector<int>& C, int x){
  return lower_bound(C.begin(), C.end(), x) - C.begin();
}

bool IsPerfectMatching(vector<pii>& edges, vector<int> U, vector<int> V){
  SortAndDedup(U);
  SortAndDedup(V);

  vector<vector<int>> adj(U.size() + V.size());
  for(pii& edge: edges){
    int i = GetCompressedValue(U, edge.first);
    int j = U.size() + GetCompressedValue(V, edge.second);
    adj[i].push_back(j);
  }

  iota(U.begin(), U.end(), 0);
  iota(V.begin(), V.end(), U.size());

  int matching = HopcroftKarpMaximumMatching().CalculateMaximumMatching(adj, U, V);

  return matching == V.size();
}

bool Solve(){
  int n;
  scanf("%d", &n);

  vector<vector<int>> a(n, vector<int>(n));
  for(int x = 0; x < n; ++x){
    for(int y = 0; y < n; ++y){
      scanf("%d", &a[x][y]);
    }
  }

  vector<vector<int>> V(B);
  vector<vector<pii>> edges(B, vector<pii>());
  for(int x = 0; x < n; ++x){
    for(int y = 0; y < n; ++y){
      V[a[x][y]].push_back(GetIndex(n, x, y));
      for(pii& move: moves){
        int nx = x + move.first, ny = y + move.second;
        if(nx < 0 || nx >= n || ny < 0 || ny >= n || a[nx][ny] != 1 + a[x][y]){
          continue;
        }
        edges[a[x][y]].push_back({GetIndex(n, x, y), GetIndex(n, nx, ny)});
      }
    }
  }

  for(int d = 1; d + 1 < B; ++d){
    SortAndDedup(V[d]);
    if(!IsPerfectMatching(edges[d], V[d], V[d + 1])){
      return false;
    }
  }

  return true;
}

int main(){
  int t;
  scanf("%d", &t);
  while(t--){
    printf("%s\n", Solve() ? "YES" : "NO");
  }
  return 0;
}