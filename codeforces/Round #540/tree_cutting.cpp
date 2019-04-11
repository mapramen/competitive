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
#define N 300001
#define LOGN 20
#define MOD 998244353

vector< vector<int> > adj(N), vertexWithColor(N);
int color[N];
ll dp[N][2];

//----------------------------------------- LCA -----------------------------------------//
int d[N], parent[N], startTime[N], finishTime[N], startTimeVertex[N], eulerTourIndexes[N];
int lg[2 * N], LCASparseTable[1 + LOGN][2 * N];
int eulerTourIndex = 0, timer = 0;

void BuildLCASparseTable(int n){
  n = 2 * n;

  for(int i = 2; i < n; ++i){
    lg[i] = 1 + lg[(i / 2)];
  }

  for(int k = 1; k <= LOGN; ++k){
    for(int i = 1, j = 1 + (1 << (k - 1)), m = n - (1 << k) + 1; i < m; ++i, ++j){
      LCASparseTable[k][i] = min(LCASparseTable[k - 1][i], LCASparseTable[k - 1][j]);
    }
  }
}

int LCA(int i, int j){
  i = eulerTourIndexes[i], j = eulerTourIndexes[j];
  
  if(i > j){
    swap(i, j);
  }

  int k = lg[j - i + 1];
  int ans = startTimeVertex[min(LCASparseTable[k][i], LCASparseTable[k][j - (1 << k) + 1])];
  return ans;
}

bool IsAncestor(int i, int j){
  return startTime[i] <= startTime[j] && finishTime[j] <= finishTime[i];
}

int Dis(int i, int j){
  int k = LCA(i, j);
  return (d[i] - d[k]) + (d[j] - d[k]);
}
//--------------------------------------- LCA Ends ---------------------------------------//

void DFS(int i, int p){
  d[i] = 1 + d[p];
  parent[i] = p;
  startTime[i] = ++timer;
  startTimeVertex[startTime[i]] = i;
  eulerTourIndexes[i] = ++eulerTourIndex;
  LCASparseTable[0][eulerTourIndexes[i]] = startTime[i];

  for(auto j : adj[i]){
    if(j == p){
      continue;
    }
    DFS(j, i);
    LCASparseTable[0][++eulerTourIndex] = startTime[i];
  }

  finishTime[i] = timer;
}

void SolveDFS(int i, int p){
  ll zeroColor = color[i] == 0;
  ll oneColor = color[i] != 0;

  for(auto j : adj[i]){
    if(j == p){
      continue;
    }
    
    SolveDFS(j, i);

    if(color[i]){
      oneColor = (oneColor * dp[j][color[j] != 0]) % MOD;
    }
    else{
      tie(zeroColor, oneColor) = make_pair((zeroColor * dp[j][0]) % MOD, (oneColor * dp[j][0] + zeroColor * dp[j][1]) % MOD);
    }
  }

  dp[i][0] = (zeroColor + oneColor);
  dp[i][1] = oneColor;
}

int main(){
  int n, m;
  scanf("%d%d", &n, &m);

  for(int i = 1; i <= n; ++i){
    scanf("%d", &color[i]);
  }

  for(int x = 1; x < n; ++x){
    int i, j;
    scanf("%d%d", &i, &j);
    adj[i].push_back(j);
    adj[j].push_back(i);
  }

  DFS(1, 0);
  BuildLCASparseTable(n);

  for(int i = 1; i <= n; ++i){
    vertexWithColor[color[i]].push_back(i);
  }

  for(int i = 1; i <= m; ++i){
    if(vertexWithColor[i].size() < 2){
      continue;
    }

    int x = vertexWithColor[i][0];
    for(auto y : vertexWithColor[i]){
      x = LCA(x, y);
    }

    for(int u : vertexWithColor[i]){
      for(int v = parent[u]; d[x] <= d[v]; v = parent[v]){
        if(color[v] == 0){
          color[v] = i;
        }
        else{
          if(color[v] != i){
            printf("0\n");
            return 0;
          }
          break;
        }
      }
    }
  }

  SolveDFS(1, 0);
  printf("%lld\n", dp[1][1]);

  return 0;
}