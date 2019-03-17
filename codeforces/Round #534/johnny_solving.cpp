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

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 250001

vector< vector<int> > adj(N);
int d[N], parent[N], maxDepthVertex = 1;
bool visited[N];
vector<int> leaves;

void DFS(int i){
  visited[i] = true;
  bool isLeaf = true;
  for(int j : adj[i]){
    if(visited[j]){
      continue;
    }
    parent[j] = i;
    d[j] = 1 + d[i];
    DFS(j);
    isLeaf = false;
  }
  if(isLeaf){
    leaves.push_back(i);
    if(d[maxDepthVertex] < d[i]){
      maxDepthVertex = i;
    }
  }
}

int Dis(int x, int y){
  if(d[x] < d[y]){
    swap(x, y);
  }
  return d[x] - d[y];
}

void PrintSimplePath(int s, int t = 1){
  for(int i = s; i != 0 && d[i] >= d[t]; i = parent[i]){
    printf("%d ", i);
  }
  printf("\n");
}

void PrintPath(){
  int i = maxDepthVertex;
  printf("PATH\n%d\n", d[i]);
  PrintSimplePath(maxDepthVertex);
}

void PrintCycle(int i){
  vector<int> v;
  
  for(int j : adj[i]){
    if(j == parent[i] || i == parent[j]){
      continue;
    }
    v.push_back(j);
    if(v.size() == 2){
      break;
    }
  }
  
  int x = v.front(), y = v.back();

  if(d[x] < d[y]){
    swap(x, y);
  }
  
  int s, t;
  
  if((1 + Dis(i, x)) % 3 != 0){
    printf("%d\n", 1 + Dis(i, x));
    s = i, t = x;
  }
  else if((1 + Dis(i, y)) % 3 != 0){
    printf("%d\n", 1 + Dis(i, y));
    s = i, t = y;
  }
  else{
    printf("%d\n%d ", 2 + Dis(x, y), i);
    s = x, t = y;
  }

  PrintSimplePath(s, t);
}

void PrintCycles(int k){
  printf("CYCLES\n");
  leaves.resize(k);
  for(int leaf : leaves){
    PrintCycle(leaf);
  }
}

int main(){
  int n, m, k;

  scanf("%d%d%d", &n, &m, &k);

  while(m--){
    int i, j;
    scanf("%d%d", &i, &j);
    adj[i].push_back(j);
    adj[j].push_back(i);
  }

  d[1] = 1;
  DFS(1);

  if((n / k) <= d[maxDepthVertex]){
    PrintPath();
  }
  else{
    PrintCycles(k);
  }
  return 0;
}