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
#define M 301
#define LOGN 17
#define MOD 1000000007

vector< vector<int> > adj(N);
int d[N], marker[N], T[N], h[N];
ll dp[M];

//----------------------------------------- LCA -----------------------------------------//
int startTime[N], finishTime[N], startTimeVertex[N], eulerTourIndexes[N];
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

void Update(int i, int x){
  for( ; i < N; i += (i & -i)){
    T[i] += x;
  }
}

void Update(int l, int r, int x){
  Update(l, x);
  Update(r + 1, -x);
}

int Query(int i){
  int ans = 0;
  for( ; i > 0; i -= (i & -i)){
    ans += T[i];
  }
  return ans;
}

int GetAncestorCount(int u, int v){
  int w = LCA(u, v);
  int ans = Query(startTime[u]) + Query(startTime[v]) - 2 * Query(startTime[w]) + marker[w] - 1;
  return ans;
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
  BuildLCASparseTable(n);

  while(q--){
    int k, m, r;
    vector<int> v;

    scanf("%d%d%d", &k, &m, &r);

    while(k--){
      int x;
      scanf("%d", &x);
      v.push_back(x);
    }

    for(int i : v){
      Update(startTime[i], finishTime[i], 1);
      marker[i] = 1;
    }

    for(int i : v){
      h[i] = GetAncestorCount(r, i);
    }

    sort(v.begin(), v.end(), [](int i, int j) { return h[i] < h[j]; });

    for(int i = 0; i <= m; ++i){
      dp[i] = 0;
    }
    dp[0] = 1;

    for(int i : v){
      int x = h[i];
      for(int j = m; j > x; --j){
        dp[j] = ((j - h[i]) * dp[j] + dp[j - 1]) % MOD;
      }
      for(int j = 0; j <= x; ++j){
        dp[j] = 0;
      }
    }

    int ans = 0;
    for(int j = 0; j <= m; ++j){
      ans = (ans + dp[j]) % MOD;
    }

    for(int i : v){
      Update(startTime[i], finishTime[i], -1);
      marker[i] = 0;
    }

    printf("%d\n", ans);
  }

  return 0;
}