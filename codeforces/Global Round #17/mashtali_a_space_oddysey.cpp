#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 200001

vector<vector<int>> adj(N);
int u[N], v[N];
bool visited[N];
char s[N];

void AddEdge(int k, int i, int j){
  u[k] = i, v[k] = j;
  adj[i].push_back(k);
  adj[j].push_back(k);
}

void DFS(int i){
  vector<int> &edgeList = adj[i];
  while(!edgeList.empty()){
    int k = edgeList.back();
    edgeList.pop_back();

    if(visited[k]){
      continue;
    }

    visited[k] = true;
    s[k] = '1' + (v[k] == i);
    
    int j = (i ^ u[k] ^ v[k]);
    DFS(j);
  }
}

int main(){
  int n, m;
  scanf("%d%d", &n, &m);

  for(int k = 0; k < m; ++k){
    int i, j, w;
    scanf("%d%d%d", &i, &j, &w);
    
    if(w == 2){
      i += n, j += n;
    }

    AddEdge(k, i, j);
  }

  int root = 2 * n + 1, ans = 0;
  for(int i = 1, j = n + 1, k = m; i <= n; ++i, ++j){
    ans += (adj[i].size() % 2);
    if(adj[i].size() % 2 == 1 && adj[j].size() % 2 == 1){
      AddEdge(++k, i, j);
      continue;
    }

    if(adj[i].size() % 2 == 1){
      AddEdge(++k, root, i);
    }

    if(adj[j].size() % 2 == 1){
      AddEdge(++k, root, j);
    }
  }

  for(int i = 1; i <= root; ++i){
    DFS(i);
  }

  printf("%d\n", ans);

  s[m] = '\0';
  printf("%s\n", s);

  return 0;
}