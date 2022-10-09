#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 100002
#define LOGN 19

vector<vector<int>> adj(N);
int parent[N], a[N];
map<int,int> startTimes[N];

//----------------------------------------- LCA -----------------------------------------//
int d[N], startTime[N], finishTime[N], startTimeVertex[N], eulerTourIndexes[N];
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

void DFS(int i, int parent){
  d[i] = 1 + d[parent];
  startTime[i] = ++timer;
  startTimeVertex[startTime[i]] = i;
  eulerTourIndexes[i] = ++eulerTourIndex;
  LCASparseTable[0][eulerTourIndexes[i]] = startTime[i];

  for(int j: adj[i]){
    if(j == parent){
      continue;
    }
    DFS(j, i);
    LCASparseTable[0][++eulerTourIndex] = startTime[i];
    startTimes[i][startTime[j]] = j;
  }

  finishTime[i] = timer;
}

void PreProcess(int n, int root){
  DFS(root, 0);
  BuildLCASparseTable(n);

  for(int i = 1; i <= n; ++i){
    startTimes[i][INT_MAX] = 0;
  }
}

int Find(int i){
  return parent[i] == i ? i : parent[i] = Find(parent[i]);
}

bool Union(int i, int j){
  i = Find(i), j = Find(j);
  if(i == j){
    return false;
  }

  if(i > j){
    swap(i, j);
  }

  parent[j] = i;
  return true;
}

void Update(int i, int x){
  a[startTime[i]] += x;
  a[finishTime[i] + 1] -= x;
}

int main(){
  int n, m;
  scanf("%d%d", &n, &m);

  for(int i = 1; i <= n; ++i){
    parent[i] = i;
  }

  vector<pii> edges;
  while(m--){
    int i, j;
    scanf("%d%d", &i, &j);
    if(Union(i, j)){
      adj[i].push_back(j);
      adj[j].push_back(i);
    }
    else{
      edges.push_back({i, j});
    }
  }

  PreProcess(n, 1);

  for(pii& edge: edges){
    auto [i, j] = edge;
    if(startTime[j] < startTime[i]){
      swap(i, j);
    }

    int k = LCA(i, j);
    if(k != i){
      Update(1, 1);
      Update(i, -1);
      Update(j, -1);
    }
    else{
      k = prev(startTimes[k].upper_bound(startTime[j]))->second;
      Update(k, 1);
      Update(j, -1);
    }
  }

  for(int i = 1; i <= n; ++i){
    a[i] += a[i - 1];
  }

  for(int i = 1; i <= n; ++i){
    if(a[startTime[i]] != 0){
      putchar('0');
    }
    else{
      putchar('1');
    }
  }
  printf("\n");

  return 0;
}