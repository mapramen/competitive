#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 100001

vector< vector<int> > adj(N);
int d[N], parent[N];

int BFS(int n, int s, int k){
  int v;
  for(int i = 1; i <= n; ++i){
    d[i] = INT_MAX;
  }

  queue<int> Q;
  d[s] = 0;
  Q.push(s);
  while(!Q.empty()){
    int i = Q.front();
    Q.pop();
    v = i;
    for(auto j : adj[i]){
      if(1 + d[i] < d[j]){
        d[j] = 1 + d[i];
        parent[j] = i;
        Q.push(j);
      }
    }
  }

  if(d[v] != 2 * k){
    return 0;
  }

  for( ; d[v] != k; v = parent[v]);

  return v;
}

bool DFS(int i, int p, int k){
  if(adj[i].size() != 1 && adj[i].size() <= 2 + (p > 0)){
    return 0;
  }

  if(adj[i].size() == 1){
    return (k ? 0 : 1);
  }

  bool valid = 1;
  for(int j : adj[i]){
    if(j == p){
      continue;
    }
    valid &= DFS(j, i, k - 1);
  }

  return valid;
}

int main(){
  int n, k;

  scanf("%d%d", &n, &k);

  for(int x = 1; x < n; ++x){
    int i, j;
    scanf("%d%d", &i, &j);
    adj[i].PB(j);
    adj[j].PB(i);
  }

  int s;
  for(s = 1; adj[s].size() > 1; ++s);

  int root = BFS(n, s, k);
  if(root <= 0 || !DFS(root, 0, k)){
    printf("No\n");
  }
  else{
    printf("Yes\n");
  }

  return 0;
}
