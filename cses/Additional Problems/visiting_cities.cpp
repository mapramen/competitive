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
#define pli pair<ll,int>
#define N 100001

vector<vector<pii>> adj(N);
vector<vector<int>> rAdj(N);
ll d[N];
int parent[N], queuedCount = 0;
bool visited[N], blocked[N], isQueued[N], isCritical[N];

priority_queue<pli,vector<pli>,greater<pli>> Q;

void Relax(int i, int p, ll x){
  if(x < d[i]){
    d[i] = x;
    parent[i] = p;
    Q.push({x, i});
  }
}

vector<int> Dijkstra(int n, int s, int t){
  for(int i = 1; i <= n; ++i){
    d[i] = LLONG_MAX;
  }

  Relax(s, 0, 0ll);

  while(!Q.empty()){
    auto [di, i] = Q.top();
    Q.pop();

    if(di != d[i]){
      continue;
    }

    for(pii p: adj[i]){
      Relax(p.first, i, di + p.second);
    }
  }

  for(int i = 1; i <= n; ++i){
    for(auto p: adj[i]){
      auto [j, x] = p;
      if(d[j] == d[i] + x){
        rAdj[j].push_back(i);
      }
    }
  }

  vector<int> ans;
  for(int i = t; ans.empty() || ans.back() != s; i = parent[i]){
    ans.push_back(i);
  }

  return ans;
}

void DFS(int i){
  if(visited[i]){
    return;
  }

  if(blocked[i]){
    if(!isQueued[i]){
      isQueued[i] = true;
      ++queuedCount;
    }
    return;
  }

  visited[i] = true;
  for(int j: rAdj[i]){
    DFS(j);
  }
}

int main(){
  int n, m;

  scanf("%d%d", &n, &m);
  while(m--){
    int i, j, k;
    scanf("%d%d%d", &i, &j, &k);
    adj[i].push_back({j, k});
  }

  vector<int> path = Dijkstra(n, 1, n);
  for(int i: path){
    blocked[i] = true;
  }

  int criticalCount = 0;
  for(int i: path){
    if(isQueued[i]){
      --queuedCount;
    }

    if(queuedCount == 0){
      isCritical[i] = true;
      ++criticalCount;
    }
    
    blocked[i] = false;
    isQueued[i] = false;
    DFS(i);
  }

  printf("%d\n", criticalCount);
  for(int i = 1; i <= n; ++i){
    if(isCritical[i]){
      printf("%d ", i);
    }
  }
  printf("\n");

  return 0;
}