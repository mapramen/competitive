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

vector<vector<int>> adj(N), rAdj(N), sAdj(N);
vector<int> topologicalOrder;
int a[N], assigned[N];
bool visited[N];
ll dp[N];

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

ll DFS(int i){
  if(visited[i]){
    return dp[i];
  }

  ll ans = 0;
  for(int j: sAdj[i]){
    ans = max(ans, DFS(j));
  }

  visited[i] = true;
  dp[i] += ans;

  return dp[i];
}

int main(){
  int n, m;

  scanf("%d%d", &n, &m);

  for(int i = 1; i <= n; ++i){
    scanf("%d", &a[i]);
  }

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
  }

  for(int i = 1; i <= n; ++i){
    int ci = assigned[i];
    dp[ci] += a[i];
    for(int j: adj[i]){
      int cj = assigned[j];
      if(cj != ci){
        sAdj[ci].push_back(cj);
      }
    }
  }

  for(int i = 1; i <= m; ++i){
    visited[i] = false;
  }

  ll ans = 0;
  for(int i = 1; i <= m; ++i){
    ans = max(ans, DFS(i));
  }

  printf("%lld\n", ans);

  return 0;
}