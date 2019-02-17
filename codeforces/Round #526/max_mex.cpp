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
#include <climits>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 200001
#define LOGN 18
#define M (1 << (1 + LOGN))

vector< vector<int> > adj(N);
int d[N], p[N], invP[N], degree[N];

void RemoveDuplicates(vector<int>& v){
  sort(v.begin(), v.end());
  v.erase(unique(v.begin(), v.end()), v.end());
}

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

//----------------------------------------- Segment Tree -----------------------------------------//
pii pathEnds[M], queryAnsPathEnds;
bool valid[M];
int queryAns;

bool IsPathSimple(vector<int>& a){
  vector<int> v(a);
  for(int i = 0; i < a.size(); ++i){
    for(int j = i + 1; j < a.size(); ++j){
      v.push_back(LCA(a[i], a[j]));
    }
  }

  RemoveDuplicates(v);

  for(auto i : v){
    degree[i] = 0;
  }

  for(auto i : v){
    int p = 0;
    for(auto j : v){
      if(j != i && IsAncestor(j, i) && d[j] > d[p]){
        p = j;
      }
    }
    if(p == 0){
      continue;
    }
    ++degree[i], ++degree[p];
    if(degree[i] > 2 || degree[p] > 2){
      return 0;
    }
  }

  return 1;
}

pii GetPathEnds(vector<int>& a){
  int e1 = a.front(), e2 = a.back(), d = Dis(e1, e2);
  for(int i = 0; i < a.size(); ++i){
    for(int j = i + 1; j < a.size(); ++j){
      int dx = Dis(a[i], a[j]);
      if(dx > d){
        d = dx;
        e1 = a[i], e2 = a[j];
      }
    }
  }
  return MP(e1, e2);
}

bool Combine(pii p, pii q, pii &r){
  if(p.first == 0 || q.first == 0){
    return false;
  }

  vector<int> v{p.first, p.second, q.first, q.second};
  RemoveDuplicates(v);
  
  if(!IsPathSimple(v)){
    return false;
  }

  r = GetPathEnds(v);
  return true;
}

void BuildSegmentTree(int k, int l, int r){
  if(l == r){
    pathEnds[k] = MP(invP[l], invP[l]);
    valid[k] = true;
  }
  else{
    BuildSegmentTree(2 * k + 1, l, (l + r) / 2);
    BuildSegmentTree(2 * k + 2, (l + r) / 2 + 1, r);
    valid[k] = (valid[2 * k + 1] && valid[2 * k + 2] && Combine(pathEnds[2 * k + 1], pathEnds[2 * k + 2], pathEnds[k]));
  }
}

void Update(int k, int l, int r, int i, int x){
  if(i < l || r < i){
    return;
  }
  else{
    if(i == l && i == r){
      invP[i] = x;
      pathEnds[k] = MP(x, x);
    }
    else{
      Update(2 * k + 1, l, (l + r) / 2, i, x);
      Update(2 * k + 2, (l + r) / 2 + 1, r, i, x);
      valid[k] = (valid[2 * k + 1] && valid[2 * k + 2] && Combine(pathEnds[2 * k + 1], pathEnds[2 * k + 2], pathEnds[k]));
    }
  }
}

void Query(int k, int l, int r){
  if(queryAns + 1 != l){
    return;
  }

  if(valid[k] && Combine(queryAnsPathEnds, pathEnds[k], queryAnsPathEnds)){
    queryAns = r;
    return;
  }

  if(l == r){
    return;
  }

  Query(2 * k + 1, l, (l + r) / 2);
  Query(2 * k + 2, (l + r) / 2 + 1, r);
}
//-------------------------------------- Segment Tree Ends --------------------------------------//

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

int Query(int n){
  queryAnsPathEnds = MP(invP[0], invP[0]);
  queryAns = -1;
  Query(0, 0, n - 1);
  return 1 + queryAns;
}

int main(){
  int n;

  scanf("%d", &n);
  for(int i = 1; i <= n; ++i){
    scanf("%d", &p[i]);
    invP[p[i]] = i;
  }

  for(int j = 2; j <= n; ++j){
    int i;
    scanf("%d", &i);
    adj[i].push_back(j);
  }

  DFS(1, 0);
  BuildLCASparseTable(n);
  BuildSegmentTree(0, 0, n - 1);

  int q;
  scanf("%d", &q);
  while(q--){
    int t;
    scanf("%d", &t);
    if(t == 1){
      int i, j;
      scanf("%d%d", &i, &j);
      Update(0, 0, n - 1, p[i], j);
      Update(0, 0, n - 1, p[j], i);
      swap(p[i], p[j]);
    }
    else{
      printf("%d\n", Query(n));
    }
  }

  return 0;
}