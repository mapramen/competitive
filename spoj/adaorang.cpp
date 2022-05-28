#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define B 256
#define N 450001
#define LOGN 19

vector<vector<int>> adj(N);
vector<vector<pii>> queries(N);
int shades[N], a[N], nxt[B], T[N], qAns[N];

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
    queries[i].clear();
    T[i] = 0;
  }

  for(int i = 0; i < B; ++i){
    nxt[i] = n + 1;
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

void PreProcess(int n, int root){
  DFS(root, 0);
  BuildLCASparseTable(n);

  for(int i = 1; i <= n; ++i){
    a[startTime[i]] = shades[i];
  }
}

void Update(int n, int i, int x){
  for( ; i != 0 && i <= n; i += (i & -i)){
    T[i] += x;
  }
}

int Query(int i){
  int ans = 0;
  for( ; i > 0; i -= (i & -i)){
    ans += T[i];
  }
  return ans;
}

void Solve(){
  int n, q, root;
  scanf("%d%d%d", &n, &q, &root);

  Reset(n);

  for(int i = 1; i <= n; ++i){
    scanf("%d", &shades[i]);
  }

  for(int x = 1; x < n; ++x){
    int i, j;
    scanf("%d%d", &i, &j);
    ++i, ++j;
    adj[i].push_back(j);
    adj[j].push_back(i);
  }

  ++root;
  PreProcess(n, root);

  for(int k = 1; k <= q; ++k){
    int i, j;
    scanf("%d%d", &i, &j);
    ++i, ++j;
    
    int u = LCA(i, j);
    queries[startTime[u]].push_back({finishTime[u], k});
  }

  for(int l = n; l != 0; --l){
    int shade = a[l];
    Update(n, nxt[shade], -1);
    Update(n, l, 1);
    nxt[shade] = l;

    for(pii& query: queries[l]){
      qAns[query.second] = Query(query.first);
    }
  }

  for(int k = 1; k <= q; ++k){
    printf("%d\n", qAns[k]);
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