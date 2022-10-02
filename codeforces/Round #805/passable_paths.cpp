#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 200001
#define LOGN 20

vector<vector<int>> adj(N);

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

void Reset(int n){
  timer = 0, eulerTourIndex = 0;

  for(int i = 0; i <= n; ++i){
    adj[i].clear();
  }
}

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
  }

  finishTime[i] = timer;
}

void PreProcess(int n){
  DFS(1, 0);
  BuildLCASparseTable(n);
}

int Dis(int i, int j){
  int k = LCA(i, j);
  return d[i] + d[j] - 2 * d[k];
}

int GetFarthestNode(vector<int>& a, int i){
  int ans = 0, k = i;
  for(int j: a){
    int dis = Dis(i, j);
    if(dis > ans){
      ans = dis, k = j;
    }
  }
  return k;
}

void Solve(){
  int n;
  scanf("%d", &n);

  Reset(n);

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
    int k;
    scanf("%d", &k);

    vector<int> v(k);
    for(int& x: v){
      scanf("%d", &x);
    }

    int x = GetFarthestNode(v, v.front()), y = GetFarthestNode(v, x);
    bool ans = true;
    for(int z: v){
      ans = ans && (Dis(x, z) + Dis(y, z) == Dis(x, y));
    }

    printf("%s\n", ans ? "YES" : "NO");
  }
}

int main(){
  int t = 1;
  while(t--){
    Solve();
  }
  return 0;
}