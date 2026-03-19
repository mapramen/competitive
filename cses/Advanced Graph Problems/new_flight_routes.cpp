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
#define N 100001

vector<vector<int>> adj(N), rAdj(N);
vector<int> topologicalOrder;
int assigned[N], leader[N], inDegree;
bool visited[N], categorised[N];

void VisitDFS(int i){
  if(visited[i]){
    return;
  }
  
  visited[i] = true;
  for(int j: adj[i]){
    VisitDFS(j);
  }

  topologicalOrder.push_back(i);
}

void AssignDFS(int i, int x){
  if(assigned[i]){
    return;
  }

  assigned[i] = x;
  for(int j: rAdj[i]){
    AssignDFS(j, x);
  }
}

int DFS(int i){
  if(visited[i]){
    return 0;
  }

  visited[i] = true;
  if(adj[i].size() == 0){
    return i;
  }

  int ans = 0;
  for(int j: adj[i]){
    ans = DFS(j);
    if(ans){
      break;
    }
  }

  return ans;
}

int AddSccEdge(vector<pii> &edges, int i, int j){
  edges.push_back({i, j});
  return j;
}

vector<pii> SccEdges(int p, vector<int> &sources, vector<int> &sinks, vector<int> &isolated){
  vector<pii> edges;

  if(p == 0){
    if(isolated.size() > 1){
      int t = isolated.back();
      for(int i: isolated){
        t = AddSccEdge(edges, t, i);
      }
    }
    return edges;
  }

  int s = sources.front(), t = sinks[p - 1];
  int m = min(sources.size(), sinks.size());

  for(int i = 1; i < p; ++i){
    AddSccEdge(edges, sinks[i - 1], sources[i]);
  }

  for(int i = p; i < m; ++i){
    AddSccEdge(edges, sinks[i], sources[i]);
  }

  for(int i: isolated){
    t = AddSccEdge(edges, t, i);
  }

  for(int i = m; i < sources.size(); ++i){
    t = AddSccEdge(edges, t, sources[i]);
  }

  for(int i = m; i < sinks.size(); ++i){
    t = AddSccEdge(edges, t, sinks[i]);
  }

  AddSccEdge(edges, t, s);

  return edges;
}

int main(){
  int n, m;

  scanf("%d%d", &n, &m);

  while(m--){
    int i, j;
    scanf("%d%d", &i, &j);
    adj[i].push_back(j);
    rAdj[j].push_back(i);
  }

  for(int i = 1; i <= n; ++i){
    VisitDFS(i);
  }
  reverse(topologicalOrder.begin(), topologicalOrder.end());

  m = 0;
  for(int i: topologicalOrder){
    AssignDFS(i, ++m);
    m -= (assigned[i] != m);
    leader[assigned[i]] = i;
  }

  for(int i = 1; i <= n; ++i){
    adj[i].clear();
  }

  for(int j = 1; j <= n; ++j){
    int aj = assigned[j];
    for(int i: rAdj[j]){
      int ai = assigned[i];
      if(aj == ai){
        continue;
      }
      adj[ai].push_back(aj);
    }
  }

  for(int i = 1; i <= n; ++i){
    rAdj[i].clear();
  }

  for(int i = 1; i <= m; ++i){
    for(int j: adj[i]){
      rAdj[j].push_back(i);
    }
  }

  int p = 0;
  vector<int> sources, sinks, isolated;

  for(int i = 1; i <= m; ++i){
    visited[i] = false;
  }

  for(int i = 1; i <= m; ++i){
    if(!rAdj[i].empty()){
      continue;
    }

    if(adj[i].empty()){
      categorised[i] = true;
      isolated.push_back(i);
      continue;
    }

    int j = DFS(i);
    if(j == 0){
      continue;
    }

    categorised[i] = true, categorised[j] = true;
    sources.push_back(i);
    sinks.push_back(j);
    ++p;
  }

  for(int i = 1; i <= m; ++i){
    if(categorised[i]){
      continue;
    }

    if(rAdj[i].empty()){
      categorised[i] = true;
      sources.push_back(i);
      continue;
    }

    if(adj[i].empty()){
      categorised[i] = true;
      sinks.push_back(i);
      continue;
    }
  }

  vector<pii> edges = SccEdges(p, sources, sinks, isolated);

  printf("%lu\n", edges.size());
  for(pii edge: edges){
    printf("%d %d\n", leader[edge.first], leader[edge.second]);
  }

  return 0;
}