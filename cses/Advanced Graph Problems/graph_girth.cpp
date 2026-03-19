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
#define N 2501

vector<vector<int>> adj(N);
vector<pii> edges;
int d[N], parent[N];
queue<int> Q;

void CheckAndPush(int i, int x, int p){
  if(d[i] <= x){
    return;
  }
  d[i] = x;
  parent[i] = p;
  Q.push(i);
}

int BFS(int n, int s){
  for(int i = 1; i <= n; ++i){
    d[i] = INT_MAX;
  }

  CheckAndPush(s, 0, 0);
  while(!Q.empty()){
    int i = Q.front();
    Q.pop();
    for(int j: adj[i]){
      CheckAndPush(j, 1 + d[i], i);
    }
  }

  int ans = INT_MAX;
  for(auto edge: edges){
    auto [i, j] = edge;
    if(d[i] == INT_MAX || d[j] == INT_MAX || i == parent[j] || j == parent[i]){
      continue;
    }
    ans = min(ans, 1 + d[i] + d[j]);
  }

  return ans;
}

int main(){
  int n, m;

  scanf("%d%d", &n, &m);

  while(m--){
    int i, j;
    scanf("%d%d", &i, &j);
    adj[i].push_back(j);
    adj[j].push_back(i);
    edges.push_back({i, j});
  }

  int ans = INT_MAX;
  for(int i = 1; i <= n; ++i){
    ans = min(ans, BFS(n, i));
  }

  if(ans == INT_MAX){
    ans = -1;
  }

  printf("%d\n", ans);
  
  return 0;
}