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
#define M (1 << (1 + LOGN))

vector< vector<int> > adj(N);
int d[N], lca[LOGN][N], startTime[N], finishTime[N], startTimeToVertex[N], timer;

void DFS(int i, int p){
  lca[0][i] = i == 1 ? 1 : p;
  startTime[i] = ++timer;
  startTimeToVertex[timer] = i;
  d[i] = 1 + d[p];

  for(int j : adj[i]){
    if(j == p){
      continue;
    }
    DFS(j, i);
  }

  adj[i].clear();
  finishTime[i] = timer;
}

void InitialiseLCATable(int n){
  for(int k = 1; k < LOGN; ++k){
    for(int i = 1; i <= n; ++i){
      lca[k][i] = lca[k - 1][lca[k - 1][i]];
    }
  }
}

int KthAncestor(int i, int k){
  for(int j = LOGN - 1; k > 0 && j > -1; --j){
    if((1 << j) <= k){
      i = lca[j][i];
      k -= (1 << j);
    }
  }
  return i;
}

//----------------------------------------- Segment Tree -----------------------------------------//
int T[M];
vector< pii > rollbacks;

inline void Combine(int k){
  const int i = T[2 * k + 1], j = T[2 * k + 2];
  T[k] = d[i] > d[j] ? i : j;
}

void BuildSegmentTree(int k, int l, int r){
  if(l == r){
    T[k] = startTimeToVertex[l];
  }
  else{
    BuildSegmentTree(2 * k + 1, l, (l + r) / 2);
    BuildSegmentTree(2 * k + 2, (l + r) / 2 + 1, r);
    Combine(k);
  }
}

void ApplyRollbacks(){
  for( ; !rollbacks.empty(); rollbacks.pop_back()){
    int k, x;
    tie(k, x) = rollbacks.back();
    T[k] = x;
  }
}

int GetDeepestNode(){
  return T[0];
}

void Update(int k, int l, int r, int ql, int qr){
  if(r < l || r < ql || qr < l){
    return;
  }

  rollbacks.push_back(make_pair(k, T[k]));
  if(ql <= l && r <= qr){
    T[k] = 0;
    return;
  }

  Update(2 * k + 1, l, (l + r) / 2, ql, qr);
  Update(2 * k + 2, (l + r) / 2 + 1, r, ql, qr);
  Combine(k);
}
//-------------------------------------- Segment Tree Ends --------------------------------------//

void PreProcess(int n){
  timer = 0;
  DFS(1, 0);

  InitialiseLCATable(n);
  BuildSegmentTree(0, 1, n);
}

int Solve(){
  int n;

  scanf("%d", &n);
  
  for(int x = 1; x < n; ++x){
    int i, j;
    scanf("%d%d", &i, &j);
    adj[i].push_back(j);
    adj[j].push_back(i);
  }

  PreProcess(n);

  int ans = 0;
  for(int k = 1; k <= n; ++k){
    for(int i = GetDeepestNode(); i != 0; i = GetDeepestNode()){
      int v = KthAncestor(i, k);
      Update(0, 1, n, startTime[v], finishTime[v]);
      ++ans;
    }
    ApplyRollbacks();
  }

  return ans;
}

int main(){
  int t;

  scanf("%d", &t);
  while(t--){
    printf("%d\n", Solve());
  }

  return 0;
}