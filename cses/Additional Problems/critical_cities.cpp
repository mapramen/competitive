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
int d[N], parent[N], queuedCount = 0;
bool visited[N], blocked[N], isQueued[N], isCritical[N];

vector<int> BFS(int n, int s, int t){
  for(int i = 1; i <= n; ++i){
    d[i] = n;
  }

  queue<int> Q;
  Q.push(s);
  d[s] = 0;

  while(!Q.empty() && d[t] == n){
    int i = Q.front();
    Q.pop();
    for(int j: adj[i]){
      if(d[j] != n){
        continue;
      }
      d[j] = 1 + d[i];
      parent[j] = i;
      Q.push(j);
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
    int i, j;
    scanf("%d%d", &i, &j);
    adj[i].push_back(j);
    rAdj[j].push_back(i);
  }

  vector<int> path = BFS(n, 1, n);
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