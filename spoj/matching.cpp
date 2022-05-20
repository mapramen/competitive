#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 100001

vector< vector<int> > adj(N);
int match[N + 1], dis[N + 1];
bool visited[N + 1];
const int inf = 1E9;

void ResetVisited(){
  for(int i = 0; i <= N; ++i){
    visited[i] = 0;
  }
}

bool BFS(vector<int>& U){
  queue<int> Q;

  for(auto u : U){
    if(match[u] == N){
      dis[u] = 0;
      Q.push(u);
    }
    else{
      dis[u] = inf;
    }
  }

  dis[N] = inf;

  while(!Q.empty()){
    int u = Q.front();
    Q.pop();
    visited[u] = 1;
    if(dis[u] < dis[N]){
      for(auto v : adj[u]){
        if(dis[match[v]] == inf){
          visited[v] = 1;
          dis[match[v]] = 1 + dis[u];
          Q.push(match[v]);
        }
      }
    }
  }

  return (dis[N] != inf);
}

bool DFS(int u){
  if(u == N){
    return true;
  }

  for(auto v : adj[u]){
    if(dis[match[v]] == 1 + dis[u]){
      if(DFS(match[v])){
        match[v] = u;
        match[u] = v;
        return true;
      }
    }
  }

  dis[u] = inf;
  return false;
}

int HopcroftKarpMaximumMatching(vector<int>& U, vector<int> &V){
  for(auto u : U){
    match[u] = N;
  }
  for(auto v : V){
    match[v] = N;
  }
  int matching = 0;
  for(ResetVisited(); BFS(U); ResetVisited()){
    for(auto u : U){
      if(match[u] == N){
        matching += DFS(u);
      }
    }
  }
  return matching;
}

int main(){
  int n, m, q;
  scanf("%d%d%d", &n, &m, &q);

  while(q--){
    int i, j;
    scanf("%d%d", &i, &j);
    --i, j += (n - 1);
    adj[i].push_back(j);
  }

  vector<int> U;
  for(int i = 0; i < n; ++i){
    U.push_back(i);
  }

  vector<int> V;
  for(int j = n; j < n + m; ++j){
    V.push_back(j);
  }

  printf("%d\n", HopcroftKarpMaximumMatching(U, V));
  
  return 0;
}