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
int assigned[N], parent[N], sz[N];
bool visited[N];

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

int Find(int i){
  return i == parent[i] ? i : parent[i] = Find(parent[i]);
}

bool Union(int i, int j){
  i = Find(i), j = Find(j);

  if(i == j){
    return false;
  }

  if(i > j){
    swap(i, j);
  }

  parent[j] = i;
  return true;
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
    ++sz[assigned[i]];
  }

  int ans = 0;
  for(int i = 1, j = 0; i <= m; ++i){
    parent[i] = i;
    if(sz[i] > 1){
      if(j){
        j = i;
      }
      ans += sz[i];
      parent[i] = j;
    }
  }

  for(int i = 1; i <= n; ++i){
    for(int j: adj[i]){
      ans += Union(assigned[i], assigned[j]);
    }
  }

  printf("%d\n", ans);

  return 0;
}