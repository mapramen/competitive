#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 100001

vector< vector<int> > adj(N), rev_adj(N), sccs(N);
int u[N], finishV[2 * N], timer, leader[N], sccOutDegree[N];
bool visited[N];
vector<int> ans(N);

void DFS1(int i){
  visited[i] = 1;
  for(auto k : adj[i]){
    if(visited[k] == 0)
      DFS1(k);
  }
  finishV[++timer] = i;
}

void DFS2(int i, int p, vector<int>& scc){
  visited[i] = 1;
  leader[i] = p;
  scc.PB(i);
  for(auto k : rev_adj[i]){
    if(visited[k] == 0)
      DFS2(k, p, scc);
  }
}

void CheckAndAddEdge(int i, int j, int h){
  if((u[i] + 1) % h == u[j]){
    adj[i].PB(j);
    rev_adj[j].PB(i);
  }
}

int main(){
  int n, m, h;

  scanf("%d%d%d", &n, &m, &h);

  for(int i = 1; i <= n; ++i)
    scanf("%d", &u[i]);

  while(m--){
    int i, j;
    scanf("%d%d", &i, &j);
    CheckAndAddEdge(i, j, h);
    CheckAndAddEdge(j, i, h);
  }

  for(int i = 1; i <= n; ++i){
    if(visited[i])
      continue;
    DFS1(i);
  }

  for(int i = 1; i <= n; ++i)
    visited[i] = 0;

  for(int x = 2 * N - 1; x > 0; --x){
    if(finishV[x] == 0)
      continue;
    int i = finishV[x];
    if(visited[i])
      continue;
    DFS2(i, i, sccs[i]);
  }

  for(int i = 1; i <= n; ++i){
    for(auto j : adj[i]){
      int pi = leader[i], pj = leader[j];
      if(pi != pj)
        ++sccOutDegree[pi];
    }
  }

  for(int i = 1; i <= n; ++i){
    if(sccs[i].size() == 0 || sccOutDegree[i] > 0)
      continue;
    if(sccs[i].size() < ans.size())
      ans = sccs[i];
  }

  printf("%lu\n", ans.size());
  for(auto x : ans)
    printf("%d ", x);
  printf("\n");

  return 0;
}
