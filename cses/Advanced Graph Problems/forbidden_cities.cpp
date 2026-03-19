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
#define N 200001

#define LOGN 17

vector<vector<int>> adj(N);
int d[N], T[LOGN + 1][N], startTime[N], endTime[N], lowTime[N], timer;
bool visited[N], isArticulationPoint[N];

void PreProcess(int n){
  for(int k = 1; k <= LOGN; ++k){
    for(int i = 1; i <= n; ++i){
      T[k][i] = T[k - 1][T[k - 1][i]];
    }
  }
}

int KthAncestor(int k, int i){
  for(int x = LOGN; x > -1; --x){
    if((k & (1 << x))){
      i = T[x][i];
      k ^= (1 << x);
    }
  }
  return i;
}

int LCA(int i, int j){
  if(d[i] > d[j]){
    swap(i, j);
  }

  j = KthAncestor(d[j] - d[i], j);

  if(i == j){
    return i;
  }

  for(int k = LOGN; k > -1; --k){
    if(T[k][i] != T[k][j]){
      i = T[k][i], j = T[k][j];
    }
  }

  return T[0][i];
}

void DFS(int i, int p){
  visited[i] = true;
  T[0][i] = p;
  d[i] = 1 + d[p];
  startTime[i] = ++timer;
  lowTime[i] = startTime[i];

  for(int j: adj[i]){
    if(j == p){
      continue;
    }

    if(visited[j]){
      lowTime[i] = min(lowTime[i], startTime[j]);
      continue;
    }

    DFS(j, i);
    lowTime[i] = min(lowTime[i], lowTime[j]);

    if(startTime[i] <= lowTime[j] && p != 0){
      isArticulationPoint[i] = true;
    }
  }

  if(p == 0 && adj[i].size() > 1){
    isArticulationPoint[i] = true;
  }

  endTime[i] = timer;
}

bool IsAncestor(int i, int j){
  return startTime[i] < startTime[j] && endTime[j] <= endTime[i];
}

bool IsArticulationPoint(int i, int j){
  if(!IsAncestor(i, j)){
    return false;
  }

  int k = KthAncestor(d[j] - d[i] - 1, j);
  return startTime[i] <= lowTime[k];
}

bool Query(int a, int b, int c){
  if(a == c || b == c){
    return false;
  }

  if(d[a] > d[b]){
    swap(a, b);
  }

  int x = LCA(a, b);
  
  if(!IsAncestor(c, a) && !IsAncestor(c, b)){
    return x != 0;
  }

  if(IsAncestor(c, x)){
    return true;
  }

  return !IsArticulationPoint(c, a) && !IsArticulationPoint(c, b);
}

int main(){
  int n, m, q;

  scanf("%d%d%d", &n, &m, &q);

  while(m--){
    int i, j;
    scanf("%d%d", &i, &j);
    adj[i].push_back(j);
    adj[j].push_back(i);
  }

  for(int i = 1; i <= n; ++i){
    if(visited[i]){
      continue;
    }
    DFS(i, 0);
  }

  PreProcess(n);

  while(q--){
    int a, b, c;
    scanf("%d%d%d", &a, &b, &c);
    printf("%s\n", Query(a, b, c) ? "YES" : "NO");
  }

  return 0;
}