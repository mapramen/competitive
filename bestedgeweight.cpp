#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 200001
#define LOGN 18
#define inf INT_MAX

vector< vector< pii > > adj(N);
int u[N], v[N], w[N], group[N], d[N], parentEdge[N], L[LOGN][N], T1[LOGN][N], T2[LOGN][N], ans[N];
bool isEdgeInMST[N];

int Find(int i){
  if(i != group[i])
    group[i] = Find(group[i]);
  return group[i];
}

bool Union(int i, int j){
  i = Find(i), j = Find(j);
  group[i] = group[j] = min(i, j);
  return (i != j);
}

void FormMST(int n, int m){
  priority_queue< pii, vector< pii >, greater< pii > > Q;

  for(int i = 1; i <= n; i++)
    group[i] = i;

  for(int e = 1; e <= m; e++)
    Q.push(MP(w[e], e));

  while(!Q.empty()){
    int i, j, e = Q.top().second;
    Q.pop();
    i = u[e], j = v[e];
    if(Union(i, j)){
      adj[i].PB(MP(j, e));
      adj[j].PB(MP(i, e));
      isEdgeInMST[e] = 1;
    }
  }
}

void DFS(int i, int p){
  for(auto ke : adj[i]){
    int k, e;
    tie(k, e) = ke;
    if(k == p)
      continue;
    d[k] = d[i] + 1;
    L[0][k] = i;
    T1[0][k] = w[e];
    parentEdge[k] = e;
    DFS(k, i);
  }
}

void PreProcess(int n){
  for(int k = 1; k < LOGN; k++){
    for(int i = 1; i <= n; i++){
      int j = L[k - 1][i];
      L[k][i] = L[k - 1][j];
      T1[k][i] = max(T1[k - 1][i], T1[k - 1][j]);
    }
  }

  for(int k = 0; k < LOGN; k++)
    for(int i = 1; i <= n; i++)
      T2[k][i] = inf;
}

int LCA(int i, int j){
  if(d[i] < d[j])
    swap(i, j);

  for(int k = LOGN - 1; k > -1 && d[i] > d[j]; k--){
    if(d[j] + (1 << k) <= d[i])
      i = L[k][i];
  }

  if(i == j)
    return i;
  else{
    for(int k = LOGN - 1; L[0][i] != L[0][j] && k > -1; k--){
      if(L[k][i] != L[k][j])
        i = L[k][i], j = L[k][j];
    }
    return L[0][i];
  }
}

int GetMax(int i, int j){
  int ans = -inf;
  for(int x = d[i] - d[j], k = LOGN - 1; x > 0 && k > -1; k--){
    if((1 << k) <= x){
      ans = max(ans, T1[k][i]);
      i = L[k][i];
      x -= (1 << k);
    }
  }
  return ans;
}

void UpdateMin(int i, int j, int val){
  for(int x = d[i] - d[j], k = LOGN - 1; x > 0 && k > -1; k--){
    if((1 << k) <= x){
      T2[k][i] = min(T2[k][i], val);
      i = L[k][i];
      x -= (1 << k);
    }
  }
}

void PostProcess(int n){
  for(int k = LOGN - 1; k > 0; k--){
    for(int i = 1; i <= n; i++){
      int j = L[k - 1][i];
      T2[k - 1][j] = min(T2[k - 1][j], T2[k][i]);
      T2[k - 1][i] = min(T2[k - 1][i], T2[k][i]);
    }
  }
}

int main(){
  int n, m;

  scanf("%d%d", &n, &m);
  for(int e = 1; e <= m; e++)
    scanf("%d%d%d", &u[e], &v[e], &w[e]);

  FormMST(n, m);
  DFS(1, 0);
  PreProcess(n);

  for(int e = 1; e <= m; e++){
    if(isEdgeInMST[e])
      continue;

    int i = u[e], j = v[e], k = LCA(i, j), c = w[e];
    ans[e] = max(GetMax(i, k), GetMax(j, k)) - 1;
    UpdateMin(i, k, c);
    UpdateMin(j, k, c);
  }

  PostProcess(n);

  for(int i = 1; i <= n; i++){
    int e = parentEdge[i], c = T2[0][i];
    if(c == inf)
      ans[e] = -1;
    else
      ans[e] = c - 1;
  }

  for(int e = 1; e <= m; e++)
    printf("%d ", ans[e]);
  printf("\n");

  return 0;
}
