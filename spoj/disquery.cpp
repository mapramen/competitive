#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 100001
#define LOGN 16

vector<vector<pii>> adj(N);
int d[N], ancestorTable[LOGN + 1][N], minEdgeTable[LOGN + 1][N], maxEdgeTable[LOGN + 1][N];

void PreProcess(int n){
  for(int k = 1; k <= LOGN; ++k){
    for(int i = 1; i <= n; ++i){
      int j = ancestorTable[k - 1][i];
      ancestorTable[k][i] = ancestorTable[k - 1][j];
      minEdgeTable[k][i] = min(minEdgeTable[k - 1][i], minEdgeTable[k - 1][j]);
      maxEdgeTable[k][i] = max(maxEdgeTable[k - 1][i], maxEdgeTable[k - 1][j]);
    }
  }
}

int KthAncestor(int k, int i){
  for(int x = LOGN; x > -1; --x){
    if((k & (1 << x))){
      i = ancestorTable[x][i];
      k ^= (1 << x);
    }
  }
  return i;
}

int LCA(int i, int j){
  if(d[i] > d[j]){
    swap(i, j);
  }

  j = KthAncestor(d[j] - d[i], j);

  if(i == j){
    return i;
  }

  for(int k = LOGN; k > -1; --k){
    if(ancestorTable[k][i] != ancestorTable[k][j]){
      i = ancestorTable[k][i], j = ancestorTable[k][j];
    }
  }

  return ancestorTable[0][i];
}

void DFS(int i, int parent, int w){
  d[i] = 1 + d[parent];
  ancestorTable[0][i] = parent;
  minEdgeTable[0][i] = w;
  maxEdgeTable[0][i] = w;

  for(pii& p: adj[i]){
    int j = p.first, w = p.second;
    if(j == parent){
      continue;
    }
    DFS(j, i, w);
  }
}

pii QueryTillAncestor(int u, int v){
  int x = d[u] - d[v], minLength = INT_MAX, maxLength = INT_MIN;
  for(int k = LOGN; k != -1; --k){
    if((x & (1 << k)) == 0){
      continue;
    }

    minLength = min(minLength, minEdgeTable[k][u]);
    maxLength = max(maxLength, maxEdgeTable[k][u]);
    
    u = ancestorTable[k][u];
  }
  return {minLength, maxLength};
}

pii Query(int i, int j){
  int k = LCA(i, j);

  pii ans1 = QueryTillAncestor(i, k);
  pii ans2 = QueryTillAncestor(j, k);

  return {min(ans1.first, ans2.first), max(ans1.second, ans2.second)};
}

int main(){
  int n;
  scanf("%d", &n);

  for(int x = 1; x < n; ++x){
    int i, j, w;
    scanf("%d%d%d", &i, &j, &w);
    adj[i].push_back({j, w});
    adj[j].push_back({i, w});
  }

  DFS(1, 0, 0);
  PreProcess(n);

  int q;
  scanf("%d", &q);

  while(q--){
    int i, j;
    scanf("%d%d", &i, &j);

    pii ans = Query(i, j);
    printf("%d %d\n", ans.first, ans.second);
  }

  return 0;
}