#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 100001

vector<vector<int>> adj(N);
int door[N];
bool blocked[N], reachable[N], visited[N];

void Reset(int n){
  for(int i = 1; i <= n; ++i){
    reachable[i] = false, blocked[i] = false, visited[i] = false;
    door[i] = 0;
    adj[i].clear();
  }
  reachable[1] = true;
}

void DFS(int i){
  if(!reachable[i] || blocked[i] || visited[i]){
    return;
  }

  visited[i] = true;
  
  blocked[door[i]] = false;
  DFS(door[i]);
  
  for(int j: adj[i]){
    reachable[j] = true;
    DFS(j);
  }
}

bool Solve(){
  int n, k, m;
  scanf("%d%d%d", &n, &k, &m);
  
  if(n == -1){
    exit(0);
  }

  Reset(n);

  while(k--){
    int i, j;
    scanf("%d%d", &i, &j);
    door[i] = j;
    blocked[j] = true;
  }

  while(m--){
    int i, j;
    scanf("%d%d", &i, &j);
    adj[i].push_back(j);
    adj[j].push_back(i);
  }

  DFS(1);

  return visited[n];
}

int main(){
  while(true){
    printf("%s\n", Solve() ? "Y" : "N");
  }
  return 0;
}