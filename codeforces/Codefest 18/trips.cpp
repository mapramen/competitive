#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 200001

set<int> adj[N];
int K, u[N], v[N], ans[N], total;
bool visited[N];
queue<int> Q;

void RemoveEdge(int i, int j);

void CheckAndEnqueue(int i){
  if(visited[i] == 0 && adj[i].size() < K){
    visited[i] = 1;
    Q.push(i);
    --total;
  }
}

void EmptyQueue(){
  while(!Q.empty()){
    int i = Q.front();
    Q.pop();
    while(adj[i].size() > 0){
      RemoveEdge(i, *adj[i].begin());
    }
  }
}

void RemoveEdge(int i, int j){
  if(adj[i].find(j) != adj[i].end()){
    adj[i].erase(j);
  }

  if(adj[j].find(i) != adj[j].end()){
    adj[j].erase(i);
  }

  CheckAndEnqueue(i);
  CheckAndEnqueue(j);
}

int main(){
  int n, m;

  scanf("%d%d%d", &n, &m, &K);

  for(int x = 1; x <= m; ++x){
    scanf("%d%d", &u[x], &v[x]);
    adj[u[x]].insert(v[x]);
    adj[v[x]].insert(u[x]);
  }

  total = n;

  for(int i = 1; i <= n; ++i){
    CheckAndEnqueue(i);
  }

  for(int x = m; x > 0; --x){
    EmptyQueue();
    ans[x] = total;
    RemoveEdge(u[x], v[x]);
  }

  for(int x = 1; x <= m; ++x){
    printf("%d\n", ans[x]);
  }

  return 0;
}
