#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 100001
#define LOGN 17

vector<vector<int>> adj(N), centroidAncestors(N);
vector<set<pii>> S(N);
int subtreeSize[N], T[LOGN + 1][N];
bool isCentroid[N], color[N];

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
  
  int sz = 1;

  for(int j: adj[i]){
    if(j == parent){
      continue;
    }
    DFS(j, i);
    sz += subtreeSize[j];
    LCASparseTable[0][++eulerTourIndex] = startTime[i];
  }

  subtreeSize[i] = sz;
  finishTime[i] = timer;
}

int SubtreeSizeDFS(int i, int p){
  int ans = 1;
  
  for(int j: adj[i]){
    if(isCentroid[j] || j == p){
      continue;
    }
    ans += SubtreeSizeDFS(j, i);
  }

  subtreeSize[i] = ans;
  return ans;
}

int FindCentroidDFS(int i, int p, int s){
  for(int j: adj[i]){
    if(!isCentroid[j] && j != p && 2 * subtreeSize[j] > s){
      return FindCentroidDFS(j, i, s);
    }
  }
  return i;
}

void CentroidDFS(int c, int i, int p){
  centroidAncestors[i].push_back(c);

  for(int j: adj[i]){
    if(isCentroid[j] || j == p){
      continue;
    }
    CentroidDFS(c, j, i);
  }
}

void CentroidDecompositionDFS(int i){
  SubtreeSizeDFS(i, 0);
  
  i = FindCentroidDFS(i, 0, subtreeSize[i]);
  isCentroid[i] = true;

  for(int j: adj[i]){
    if(isCentroid[j]){
      continue;
    }
    CentroidDecompositionDFS(j);
  }

  isCentroid[i] = false;
  CentroidDFS(i, i, 0);
}

int Dist(int i, int j){
  int k = LCA(i, j);
  return (d[i] - d[k]) + (d[j] - d[k]);
}

void PreProcess(int n){
  DFS(1, 0);
  CentroidDecompositionDFS(1);
  BuildLCASparseTable(n);

  for(int i = 1; i <= n; ++i){
    S[i].insert({1E9, 0});
  }
}

void Add(int i){
  for(int c: centroidAncestors[i]){
    S[c].insert({Dist(i, c), i});
  }
}

void Remove(int i){
  for(int c: centroidAncestors[i]){
    S[c].erase({Dist(i, c), i});
  }
}

void Update(int i){
  color[i] = !color[i];
  
  if(color[i]){
    Add(i);
  }
  else{
    Remove(i);
  }
}

int Query(int i){
  int ans = 1E9;
  for(int c: centroidAncestors[i]){
    ans = min(ans, Dist(i, c) + S[c].begin()->first);
  }
  return ans == 1E9 ? -1 : ans;
}

int main(){
  int n;
  scanf("%d", &n);

  for(int x = 1; x < n; ++x){
    int i, j;
    scanf("%d%d", &i, &j);
    adj[i].push_back(j);
    adj[j].push_back(i);
  }

  PreProcess(n);

  int q;
  scanf("%d", &q);

  while(q--){
    int t, i;
    scanf("%d%d", &t, &i);

    if(t == 0){
      Update(i);
    }
    else{
      printf("%d\n", Query(i));
    }
  }

  return 0;
}