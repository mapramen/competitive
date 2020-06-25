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
int d[N], T[LOGN + 1][N], dp[N];

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

void Update(int i, int j){
  ++dp[i], ++dp[j];

  int k = LCA(i, j);
  --dp[k], --dp[T[0][k]];
}

void DFS(int i, int p){
  T[0][i] = p;
  d[i] = 1 + d[p];

  for(int j: adj[i]){
    if(j == p){
      continue;
    }
    DFS(j, i);
  }
}

void ComputeDFS(int i, int p){
  for(int j: adj[i]){
    if(j == p){
      continue;
    }
    ComputeDFS(j, i);
    dp[i] += dp[j];
  }
}

int main(){
  int n, q;

  scanf("%d%d", &n, &q);

  for(int x = 1; x < n; ++x){
    int i, j;
    scanf("%d%d", &i, &j);
    adj[i].push_back(j);
    adj[j].push_back(i);
  }

  DFS(1, 0);
  PreProcess(n);

  while(q--){
    int i, j;
    scanf("%d%d", &i, &j);
    Update(i, j);
  }

  ComputeDFS(1, 0);

  for(int i = 1; i <= n; ++i){
    printf("%d ", dp[i]);
  }
  printf("\n");
  
  return 0;
}