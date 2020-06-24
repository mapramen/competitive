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

vector<pii> edges;
vector<vector<int>> adj(N);
bool visited[N];

void DFS(int i){
  if(visited[i]){
    return;
  }

  visited[i] = true;
  for(int j: adj[i]){
    DFS(j);
  }
}

bool Check(int n, bool reverseEdge){
  for(int i = 1; i <= n; ++i){
    visited[i] = false;
    adj[i].clear();
  }
  
  for(pii edge: edges){
    auto [i, j] = edge;
    if(reverseEdge){
      swap(i, j);
    }
    adj[i].push_back(j);
  }

  DFS(1);

  for(int i = 1; i <= n; ++i){
    if(!visited[i]){
      printf("NO\n");
      if(reverseEdge){
        printf("%d 1\n", i);
      }
      else{
        printf("1 %d\n", i);
      }
      return false;
    }
  }

  return true;
}

int main(){
  int n, m;

  scanf("%d%d", &n, &m);

  while(m--){
    int i, j;
    scanf("%d%d", &i, &j);
    edges.push_back({i, j});
  }

  if(Check(n, false) && Check(n, true)){
    printf("YES\n");
  }
  
  return 0;
}