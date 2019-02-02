// Sample DFS/BFS code
// Nodes are [1, n]

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define MAXN 100001

vector< vector<int> > adj(MAXN);
int d[MAXN], parent[MAXN], visited[MAXN];

void AddDirectedEdge(int i, int j){
  adj[i].PB(j);
}

void AddUndirectedEdge(int i, int j){
  adj[i].PB(j);
  adj[j].PB(i);
}

void DFS(int i){
  visited[i] = 1;
  d[i] = 1 + d[parent[i]];

  for(auto k : adj[i]){
    if(visited[k])
      continue;

    parent[k] = i;
    DFS(k);
  }
}

void BFS(int s){
  queue<int> Q;

  for(int i = 1; i < MAXN; ++i)
    visited[i] = 0;

  Q.push(s);
  d[s] = 0;
  visited[s] = 1;

  while(!Q.empty()){
    int i = Q.front();
    Q.pop();

    for(auto k : adj[i]){
      if(visited[k])
        continue;
      d[k] = 1 + d[i];
      parent[k] = i;
      visited[k] = 1;
      Q.push(k);
    }
  }
}

int main(){


  return 0;
}
