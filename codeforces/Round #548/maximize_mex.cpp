#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <vector>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <deque>
#include <cmath>
#include <utility>
#include <algorithm>
#include <bitset>
#include <climits>
#include <random>
#include <chrono>
#include <cassert>

using namespace std;

typedef long long ll;
typedef long long LL;

#define pii pair< int, int >
#define pll pair< ll, ll >
#define N 10005

vector< vector<int> > adj(N), pendingEdges(N);
vector<int> U, V;
int match[N + 1], dis[N + 1], matching;
bool visited[N + 1], marked[N];
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
  for(ResetVisited(); BFS(U); ResetVisited()){
    for(auto u : U){
      if(match[u] == N){
        matching += DFS(u);
      }
    }
  }
  return matching;
}

int n, m, p[N], c[N], queries[N], ans[N], k;

void Initialise(){
  for(int i = 0; i < N; ++i){
    match[i] = N;
  }
  matching = 0;
  for(int i = 1; i <= m; ++i){
    U.push_back(i);
  }
}

void AddEdge(int u, int v){
  if(v <= k){
    adj[u].push_back(m + v);
  }
  else{
    pendingEdges[v].push_back(u);
  }
}

void RelaxEdge(){
  for(int u : pendingEdges[k]){
    adj[u].push_back(m + k);
  }
}

int Relax(){
  for( ; HopcroftKarpMaximumMatching(U, V) == k; ){
    ++k;
    RelaxEdge();
    V.push_back(m + k);
  }
  return k - 1;
}

int main(){
  int q;

  scanf("%d%d", &n, &m);
  for(int i = 1; i <= n; ++i){
    scanf("%d", &p[i]);
    ++p[i];
  }

  for(int i = 1; i <= n; ++i){
    scanf("%d", &c[i]);
  }

  scanf("%d", &q);

  for(int i = 1; i <= q; ++i){
    scanf("%d", &queries[i]);
    marked[queries[i]] = 1;
  }

  for(int i = 1; i <= n; ++i){
    if(marked[i]){
      continue;
    }
    AddEdge(c[i], p[i]);
  }

  Initialise();
  ans[q] = Relax();

  for(int x = q; x > 0; --x){
    int i = queries[x];
    AddEdge(c[i], p[i]);
    ans[x - 1] = Relax();
  }

  for(int i = 1; i <= q; ++i){
    printf("%d\n", ans[i]);
  }

  return 0;
}