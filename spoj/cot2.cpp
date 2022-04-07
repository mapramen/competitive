#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define tq tuple<int,int,int,int,int>
#define N 40001
#define M 100001
#define LOGN 17

//----------------------------------------- LCA -----------------------------------------//
int startTime[N], finishTime[N], startTimeVertex[4 * N], eulerTour[4 * N], timer = 0;
int lg[4 * N], LCASparseTable[1 + LOGN][4 * N];

void BuildLCASparseTable(int n){
  n = 4 * n;

  for(int i = 2; i < n; ++i){
    lg[i] = 1 + lg[(i / 2)];
  }

  for(int i = 1; i <= n; ++i){
    LCASparseTable[0][i] = startTime[eulerTour[i]];
  }

  for(int k = 1; k <= LOGN; ++k){
    for(int i = 1, j = 1 + (1 << (k - 1)), m = n - (1 << k) + 1; i < m; ++i, ++j){
      LCASparseTable[k][i] = min(LCASparseTable[k - 1][i], LCASparseTable[k - 1][j]);
    }
  }
}

int LCA(int i, int j){
  i = startTime[i], j = startTime[j];
  
  if(i > j){
    swap(i, j);
  }

  int k = lg[j - i + 1];
  int ans = startTimeVertex[min(LCASparseTable[k][i], LCASparseTable[k][j - (1 << k) + 1])];
  return ans;
}
//--------------------------------------- LCA Ends ---------------------------------------//

vector<vector<int>> adj(N);
int a[N], c[N], qAns[M], BLOCK_SIZE, dCount;
bool visited[N];
vector<tq> queries;

void DFS(int i, int p){
  eulerTour[++timer] = i;
  startTime[i] = timer;
  startTimeVertex[startTime[i]] = i;

  for(int j: adj[i]){
    if(j == p){
      continue;
    }
    eulerTour[++timer] = i;
    DFS(j, i);
    eulerTour[++timer] = i;
  }

  eulerTour[++timer] = i;
  finishTime[i] = timer;
}

void PreProcess(int n, int m){
  DFS(1, 0);
  BuildLCASparseTable(n);
  BLOCK_SIZE = max(1, (int)(4 * n / sqrt(m)));

  for(int i = 1; i <= timer; ++i){
    int v = eulerTour[i];
    if(i != startTime[v] && i != finishTime[v]){
      eulerTour[i] = 0;
    }
  }

  vector<int> c(n);
  for(int i = 1; i <= n; ++i){
    c[i - 1] = a[i];
  }
  sort(c.begin(), c.end());
  c.erase(unique(c.begin(), c.end()), c.end());

  for(int i = 1; i <= n; ++i){
    a[i] = lower_bound(c.begin(), c.end(), a[i]) - c.begin() + 1;
  }

  dCount = 0;
}

tq GetMOQuery(int k, int u, int v){
  int w = LCA(u, v);

  if(w == v){
    swap(u, v);
  }

  if(w == u){
    return {finishTime[v] / BLOCK_SIZE, finishTime[u], finishTime[v], 0, k};
  }

  if(finishTime[v] < startTime[u]){
    swap(u, v);
  }

  return {finishTime[u] / BLOCK_SIZE, startTime[v], finishTime[u], w, k};
}

void Update(int v, int val){
  if(v == 0){
    return;
  }

  int x = a[v];
  c[x] += val;

  if(c[x] == 1 && val == 1){
    ++dCount;
  }

  if(c[x] == 0 && val == -1){
    --dCount;
  }
}

void Toggle(int i){
  int v = eulerTour[i];
  Update(v, visited[v] ? -1 : 1);
  visited[v] = !visited[v];
}

int main(){
  int n, m;
  scanf("%d%d", &n, &m);

  for(int i = 1; i <= n; ++i){
    scanf("%d", &a[i]);
  }

  for(int x = 1; x < n; ++x){
    int i, j;
    scanf("%d%d", &i, &j);
    
    adj[i].push_back(j);
    adj[j].push_back(i);
  }

  PreProcess(n, m);

  for(int k = 1; k <= m; ++k){
    int u, v;
    scanf("%d%d", &u, &v);
    queries.push_back(GetMOQuery(k, u, v));
  }
  sort(queries.begin(), queries.end());

  int L = 1, R = 0;
  for(tq& q: queries){
    int r = get<1>(q), l = get<2>(q), i = get<3>(q), k = get<4>(q);

    for(++R; R <= r; ++R){
      Toggle(R);
    }
    --R;

    for( ; r < R; --R){
      Toggle(R);
    }

    for(--L; l <= L; --L){
      Toggle(L);
    }
    ++L;

    for( ; L < l; ++L){
      Toggle(L);
    }

    Update(i, 1);
    qAns[k] = dCount;
    Update(i, -1);
  }

  for(int k = 1; k <= m; ++k){
    printf("%d\n", qAns[k]);
  }

  return 0;
}