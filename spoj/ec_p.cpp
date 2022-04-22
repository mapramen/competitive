#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 701

vector<vector<int>> adj(N);
int parent[N], startTime[N], earliestStartTime[N], timer;
bool visited[N];
vector<pii> bridges;

void Reset(int n){
  for(int i = 1; i <= n; ++i){
    visited[i] = false;
    adj[i].clear();
  }
  timer = 0;
  bridges.clear();
}

void AddBridge(int i, int j){
  if(i > j){
    swap(i, j);
  }
  bridges.push_back({i, j});
}

void DFS(int i, int p){
  if(visited[i]){
    return;
  }

  visited[i] = true;
  parent[i] = p;
  startTime[i] = ++timer;
  earliestStartTime[i] = startTime[i];

  int est = startTime[i];
  
  for(int j: adj[i]){
    if(j == p){
      continue;
    }
    
    DFS(j, i);
    est = min(est, earliestStartTime[j]);

    if(earliestStartTime[j] > startTime[i]){
      AddBridge(i, j);
    }
  }

  earliestStartTime[i] = est;
}

void Solve(){
  int n, m;
  scanf("%d%d", &n, &m);

  while(m--){
    int i, j;
    scanf("%d%d", &i, &j);
    adj[i].push_back(j);
    adj[j].push_back(i);
  }

  DFS(1, 0);

  if(bridges.empty()){
    printf("Sin bloqueos\n");
  }
  else{
    sort(bridges.begin(), bridges.end());

    printf("%lu\n", bridges.size());
    for(pii& bridge: bridges){
      printf("%d %d\n", bridge.first, bridge.second);
    }
  }

  Reset(n);
}

int main(){
  int t;
  scanf("%d", &t);
  for(int k = 1; k <= t; ++k){
    printf("Caso #%d\n", k);
    Solve();
  }
  return 0;
}