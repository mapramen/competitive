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
#define LOGN 17

vector< vector<int> > adj(N);
int c[N], d[N];
ll a[N];
vector< set<int> > S(N);

//----------------------------------------- LCA -----------------------------------------//
int startTime[N], finishTime[N], startTimeVertex[N + 1], eulerTourIndexes[N];
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
//--------------------------------------- LCA Ends ---------------------------------------//

void DFS(int i, int p){
  d[i] = 1 + d[p];
  a[i] += a[p];
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

  adj[i].clear();

  finishTime[i] = timer;
}

inline int GetInterestingAncestor(const int i, const int x){
  const int j = LCA(i, startTimeVertex[*prev(S[x].lower_bound(startTime[i]))]);
  const int k = LCA(i, startTimeVertex[*S[x].upper_bound(startTime[i])]);

  return d[j] > d[k] ? j : k;
}

inline ll GetContribution(const int i, const int x){
  const int j = GetInterestingAncestor(i, x);
  return a[i] - a[j];
}

inline ll Add(const int i, const int x){
  S[x].insert(startTime[i]);
  c[i] = x;
  return GetContribution(i, x);
}

inline ll Remove(const int i){
  ll ans = - GetContribution(i, c[i]);
  S[c[i]].erase(startTime[i]);
  return ans;
}

inline ll Update(const int i, const int x){
  ll ans = Remove(i);
  return ans + Add(i, x);
}

ll PreProcess(int n){
  eulerTourIndex = 0, timer = 0;
  DFS(1, 0);
  BuildLCASparseTable(n);

  for(int i = 1; i <= n; ++i){
    S[i].insert(0);
    S[i].insert(N);
  }

  ll ans = 0;
  for(int i = 1; i <= n; ++i){
    ans += Add(i, c[i]);
  }

  return ans;
}

void Solve(){
  int n, q;

  scanf("%d%d", &n, &q);
  for(int x = 1; x < n; ++x){
    int i, j;
    scanf("%d%d", &i, &j);
    adj[i].push_back(j);
    adj[j].push_back(i);
  }

  for(int i = 1; i <= n; ++i){
    scanf("%d", &c[i]);
  }

  for(int i = 1; i <= n; ++i){
    scanf("%lld", &a[i]);
  }

  ll ans = PreProcess(n);

  while(q--){
    int i, x;
    scanf("%d%d", &i, &x);
    ans += Update(i, x);
    printf("%lld\n", ans);
  }

  for(int i = 1; i <= n; ++i){
    S[i].clear();
  }
}

int main(){
  int t;
  scanf("%d", &t);
  while(t--){
    Solve();
  }
  return 0;
}