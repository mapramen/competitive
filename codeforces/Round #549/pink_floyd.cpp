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

#define pii pair< int, int >
#define pll pair< ll, ll >
#define N 100001

vector< vector<int> > adj(N), rAdj(N), components, sAdj;
vector<int> outOrder;
int componentNos[N], totalComponents, inDegrees[N];
bool visited[N];
queue<int> Q;

bool Query(int a, int b){
  printf("? %d %d\n", a, b);
  fflush(stdout);
  int x;
  scanf("%d", &x);
  return x == 1;
}

void DFS(int i){
  visited[i] = true;
  for(int j : adj[i]){
    if(visited[j]){
      continue;
    }
    DFS(j);
  }
  outOrder.push_back(i);
}

void SccDFS(int i){
  componentNos[i] = totalComponents;
  for(int j : rAdj[i]){
    if(componentNos[j]){
      continue;
    }
    SccDFS(j);
  }
}

void CheckAndAddToQueue(int i){
  if(inDegrees[i] == 0){
    Q.push(i);
  }
}

void FreeDFS(int i){
  for(int j : sAdj[i]){
    --inDegrees[j];
    CheckAndAddToQueue(j);
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

  for(int i = 1; i <= n; ++i){
    if(visited[i]){
      continue;
    }
    DFS(i);
  }

  reverse(outOrder.begin(), outOrder.end());
  for(int i : outOrder){
    if(componentNos[i]){
      continue;
    }
    ++totalComponents;
    SccDFS(i);
  }

  components.resize(totalComponents + 1);
  for(int i = 1; i <= n; ++i){
    components[componentNos[i]].push_back(i);
  }

  sAdj.resize(totalComponents + 1);
  for(int i = 1; i <= n; ++i){
    int ci = componentNos[i];
    for(int j : adj[i]){
      int cj = componentNos[j];
      if(cj != ci){
        sAdj[ci].push_back(cj);
      }
    }
  }

  for(int i = 1; i <= totalComponents; ++i){
    for(int j : sAdj[i]){
      ++inDegrees[j];
    }
  }

  for(int i = 1; i <= totalComponents; ++i){
    CheckAndAddToQueue(i);
  }

  int V = Q.front();
  for(Q.pop(); !Q.empty(); Q.pop()){
    int U = Q.front();

    while(!components[U].empty() && !components[V].empty()){
      if(Query(components[U].back(), components[V].back())){
        components[V].pop_back();
      }
      else{
        components[U].pop_back();
      }
    }

    if(!components[U].empty()){
      swap(U, V);
    }

    FreeDFS(U);
  }

  printf("! %d\n", components[V].back());
  fflush(stdout);

  return 0;
}