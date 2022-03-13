#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 10001

vector<vector<int>> adj(N);
int parent[N], startTime[N], earliestStartTime[N], timer;
bool visited[N];

void Reset(int n){
  for(int i = 1; i <= n; ++i){
    visited[i] = false;
    adj[i].clear();
  }
  timer = 0;
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
  }
  earliestStartTime[i] = est;
}

int Solve(){
  int n, m;
  scanf("%d%d", &n, &m);

  if(n == 0){
    exit(0);
  }

  while(m--){
    int i, j;
    scanf("%d%d", &i, &j);
    adj[i].push_back(j);
    adj[j].push_back(i);
  }

  DFS(1, 0);

  int ans = 0;
  for(int i = 1; i <= n; ++i){
    int c = 0;
    bool is_articulation = false;
    for(int j: adj[i]){
      if(parent[j] != i){
        continue;
      }
      ++c;
      is_articulation = is_articulation || (earliestStartTime[j] >= startTime[i]);
    }
    ans += (is_articulation && (i != 1 || c > 1));
  }

  Reset(n);

  return ans;
}

int main(){
  while(true){
    printf("%d\n", Solve());
  }
  return 0;
}