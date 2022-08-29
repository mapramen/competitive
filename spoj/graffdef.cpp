#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 100001
#define M 500001

vector<vector<int>> adj(N);
int edge_xor[M], u[M], v[M], start_time[N], earliest_time[N], parent[N], sz[N], timer = 0;
bool visited[N], is_bridge[M];

void Reset(int n){
  for(int i = 1; i <= n; ++i){
    parent[i] = i, sz[i] = 1;
  }
}

int Find(int i){
  return parent[i] == i ? i : parent[i] = Find(parent[i]);
}

void Union(int i, int j){
  i = Find(i), j = Find(j);
  if(i == j){
    return;
  }

  if(i > j){
    swap(i, j);
  }

  parent[j] = i;
  sz[i] += sz[j];
}

void BridgeDFS(int i, int p){
  if(visited[i]){
    return;
  }

  visited[i] = true;
  start_time[i] = ++timer;
  earliest_time[i] = start_time[i];

  for(int e: adj[i]){
    int j = edge_xor[e] ^ i;
    if(j == p){
      continue;
    }

    BridgeDFS(j, i);
    earliest_time[i] = min(earliest_time[i], earliest_time[j]);
    is_bridge[e] = earliest_time[j] > start_time[i];
  }
}

int main(){
  int n, m;
  scanf("%d%d", &n, &m);

  for(int e = 1; e <= m; ++e){
    scanf("%d%d", &u[e], &v[e]);
    adj[u[e]].push_back(e);
    adj[v[e]].push_back(e);
    edge_xor[e] = u[e] ^ v[e];
  }

  Reset(n);
  BridgeDFS(1, 0);

  for(int e = 1; e <= m; ++e){
    if(!is_bridge[e]){
      Union(u[e], v[e]);
    }
  }

  double ans = 0;
  for(int i = 1; i <= n; ++i){
    if(Find(i) != i){
      continue;
    }
    ans += 1ll * sz[i] * (sz[i] - 1);
  }

  ans /= 1ll * n * (n - 1);
  ans = 1 - ans;

  printf("%.5lf\n", ans);

  return 0;
}