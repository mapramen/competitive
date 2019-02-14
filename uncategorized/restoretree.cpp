#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 30001

vector< vector<int> > adj(N), d(N), nodes(N), depthNodes(N), parent(N);
int n, root, t[N];
bool valid = 1, visited[N];
vector<int> v;

void ReadDistance(){
  int k = 0, c = 0;
  for(int i = 1; i <= n; ++i){
    scanf("%d", &t[i]);
    c += (t[i] == 0);
    if(t[i] == 0)
      k = i;
  }

  valid &= (c == 1);

  if(valid){
    d[k].resize(n + 1);
    for(int i = 1; i <= n; ++i)
      d[k][i] = t[i];
    v.PB(k);
  }

  if(valid && root == 0){
    root = k;
    parent[root].PB(root);
    visited[root] = 1;
    for(int i = 1; i <= n; ++i)
      depthNodes[d[root][i]].PB(i);
  }
}

void AddEdge(int i, int j){
  if(d[root][i] > d[root][j])
    swap(i, j);

  if(visited[j] == 0){
    adj[i].PB(j);
    adj[j].PB(i);
    visited[j] = 1;
  }
}

void FixSpecialNode(int k){
  if(k == root)
    return ;

  for(int i = 0; i <= n; ++i)
    t[i] = 0;

  for(int i = 1; i <= n; ++i){
    if(d[root][i] + d[k][i] == d[root][k])
      t[d[k][i]] = i;
  }

  for(int i = 0; i < d[root][k]; ++i)
    AddEdge(t[i], t[i + 1]);

  parent[k].resize(d[root][k] + 1);
  for(int i = 0; i <= d[root][k]; ++i)
    parent[k][i] = t[i];
}

void FixSpecialNodes(){
  if(valid == 0)
    return ;

  for(auto k : v)
    FixSpecialNode(k);
}

int GetAncestor(int k, int i){
  // printf("GetAncestor %d %d\n", k, i);
  int x = d[root][k] + d[k][i] - d[root][i];
  // printf("GetAncestor %d %d: %d\n", k, i, x);
  if(x % 2 != 0 || x < 0)
    return 0;
  else
    return parent[k][x / 2];
}

void FixNonSpecialNode(int i){
  int j = 0;
  for(auto k : v){
    int x = GetAncestor(k, i);
    if(x == 0)
      continue;
    if(j == 0 || d[root][x] > d[root][j])
      j = x;
  }

  if(j == 0){
    valid = 0;
    return ;
  }

  int x = d[root][i] - d[root][j];

  if(x > nodes[j].size())
    valid = 0;
  else{
    AddEdge(nodes[j][x - 1], i);
    if(x == nodes[j].size())
      nodes[j].PB(i);
  }
  // printf("FixNonSpecialNode %d: %d %d %d\n", i, j, x, valid);
}

void FixNonSpecialNodes(){
  if(valid == 0)
    return ;

  for(int i = 1; i <= n; ++i)
    nodes[i].PB(i);

  for(auto u : depthNodes){
    for(auto i : u){
      if(visited[i] == 0)
        FixNonSpecialNode(i);
      if(valid == 0)
        break;
    }
    if(valid == 0)
      break;
  }
}

void CheckDFS(int i){
  for(auto k : adj[i]){
    if(t[k] == n){
      t[k] = 1 + t[i];
      CheckDFS(k);
    }
  }
}

void CheckSpecialNode(int s){
  if(valid == 0)
    return ;

  for(int i = 1; i <= n; ++i)
    t[i] = n;

  t[s] = 0;
  CheckDFS(s);

  for(int i = 1; i <= n && valid == 1; ++i)
    valid &= (t[i] == d[s][i]);
}

void Check(){
  if(valid == 0)
    return ;

  for(auto k : v)
    CheckSpecialNode(k);
}

void PrintDFS(int i, int p){
  for(auto k : adj[i]){
    if(k != p){
      printf("%d %d\n", i, k);
      PrintDFS(k, i);
    }
  }
}

int main(){
  int k;

  scanf("%d%d", &n, &k);

  while(k--)
    ReadDistance();

  FixSpecialNodes();
  FixNonSpecialNodes();
  // Check();

  if(valid)
    PrintDFS(1, 0);
  else
    printf("-1\n");

  return 0;
}
