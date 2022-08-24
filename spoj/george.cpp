#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 1001
#define M 10001

vector<vector<int>> adj(N);
map<pii,int> edge_index_map;
int a[N], edge_xor[M], w[M], L[M], R[M], d[N];
priority_queue<pii,vector<pii>,greater<pii>> Q;

void CheckAndPush(int i, int di){
  if(di < d[i]){
    d[i] = di;
    Q.push({di, i});
  }
}

int main(){
  int n, m;
  scanf("%d%d", &n, &m);

  int s, t, k, g;
  scanf("%d%d%d%d", &s, &t, &k, &g);

  for(int i = 1; i <= g; ++i){
    scanf("%d", &a[i]);
  }

  for(int e = 1; e <= m; ++e){
    int i, j;
    scanf("%d%d%d", &i, &j, &w[e]);
    adj[i].push_back(e), adj[j].push_back(e);
    edge_xor[e] = i ^ j;
    edge_index_map[{i, j}] = e, edge_index_map[{j, i}] = e;
  }

  for(int x = 1, y = 2, z = 0; y <= g; ++x, ++y){
    int e = edge_index_map[{a[x], a[y]}];
    L[e] = z, R[e] = z + w[e];
    z += w[e];
  }

  for(int i = 1; i <= n; ++i){
    d[i] = INT_MAX;
  }

  CheckAndPush(s, k);

  while(!Q.empty()){
    int i, di;
    tie(di, i) = Q.top();
    Q.pop();

    if(di > d[i]){
      continue;
    }

    for(int e: adj[i]){
      int dj = (di >= L[e] && di < R[e] ? R[e] : di) + w[e];
      CheckAndPush(edge_xor[e] ^ i, dj);
    }
  }

  printf("%d\n", d[t] - k);

  return 0;
}