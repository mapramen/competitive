#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define piii pair< int, pii >
#define PB push_back
#define MP make_pair
#define N 3001
#define M 400001

vector< vector<int> > adj(N), curAdj(N);
vector< vector< piii > > tQueries(N);
vector< vector< pii > > tsQueries(N);
int d[N], path[N], parent[N], ans[M];
bool visited[N], reachable[N];

void DFS(int i){
  visited[i] = 1;
  for(auto k : adj[i]){
    if(visited[k])
      continue;
    DFS(k);
  }
}

void QueryDFS(int i){
  d[i] = d[parent[i]] + 1;
  path[d[i]] = i;
  visited[i] = 1;

  for(auto k : curAdj[i]){
    if(visited[k])
      continue;
    parent[k] = i;
    QueryDFS(k);
  }

  for(auto p : tsQueries[i]){
    int k, x;
    tie(k, x) = p;
    if(k <= d[i])
      ans[x] = path[d[i] - k + 1];
  }
}

int main(){
  int n, m, q;

  scanf("%d%d%d", &n, &m, &q);

  while(m--){
    int i, j;
    scanf("%d%d", &i, &j);
    adj[j].PB(i);
  }

  for(int x = 1; x <= q; ++x){
    int i, j, k;
    scanf("%d%d%d", &i, &j, &k);
    tQueries[j].PB(MP(i, MP(k, x)));
    ans[x] = -1;
  }

  for(int t = 1; t <= n; ++t){
    for(int i = 1; i <= n; ++i){
      parent[i] = n + 1;
      d[i] = path[i] = 0;
      visited[i] = 0;
      tsQueries[i].clear();
      curAdj[i].clear();
    }

    DFS(t);

    for(int i = 1; i <= n; ++i){
      if(visited[i] == 0)
        continue;
      for(auto k : adj[i])
        parent[k] = min(parent[k], i);
    }

    for(int i = 1; i <= n; ++i){
      if(parent[i] <= n)
        curAdj[parent[i]].PB(i);
    }

    for(auto p : tQueries[t])
      tsQueries[p.first].PB(p.second);

    for(int i = 1; i <= n; ++i)
      visited[i] = 0;

    parent[t] = 0;
    QueryDFS(t);
  }

  for(int x = 1; x <= q; ++x)
    printf("%d\n", ans[x]);

  return 0;
}
