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

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 201

vector< vector<int> > adj(N);
int match[N + 1], dis[N + 1];
bool visited[N + 1], minimumVertexCover[N], maximumIndependentSet[N];
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

void FillMinimumVertexCover(vector<int> &U, vector<int> &V){
  for(auto u : U){
    minimumVertexCover[u] = (match[u] != N && visited[u] == 0);
  }
  for(auto v : V){
    minimumVertexCover[v] = (match[v] != N && visited[v] == 1);
  }
}

void FillMaximumIndependentSet(vector<int> &U, vector<int> &V){
  for(auto u : U){
    maximumIndependentSet[u] = (match[u] == N || visited[u] == 1);
  }
  for(auto v : V){
    maximumIndependentSet[v] = (match[v] == N || visited[v] == 0);
  }
}

int main(){
  int n;
  vector<int> U, V;

  cin >> n;
  for(int i = 1; i <= n; ++i){
    string s;
    cin >> s;
    
    for(int j = 1; j <= n; ++j){
      if(s[j - 1] == 'o'){
        adj[i].push_back(n + j);
      }
    }
    
    U.push_back(i);
    V.push_back(n + i);
  }

  HopcroftKarpMaximumMatching(U, V);
  FillMinimumVertexCover(U, V);

  int ans = 0;
  for(int i = 1; i <= 2 * n; ++i){
    ans += minimumVertexCover[i];
  }

  printf("%d\n", ans);
  for(int i = 1; i <= 2 * n; ++i){
    if(minimumVertexCover[i]){
      int x = 1 + (i > n), j = i > n ? i - n : i;
      printf("%d %d\n", x, j);
    }
  }

  return 0;
}