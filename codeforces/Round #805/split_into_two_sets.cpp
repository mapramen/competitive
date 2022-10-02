#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 200001

vector<vector<int>> adj(N);
bool visited[N], color[N];

void Reset(int n){
  for(int i = 1; i <= n; ++i){
    adj[i].clear();
    visited[i] = false;
  }
}

bool DFS(int i, bool c){
  if(adj[i].size() > 2){
    return false;
  }
  
  if(visited[i]){
    return color[i] == c;
  }

  visited[i] = true;
  color[i] = c;

  bool ans = true;
  for(int j: adj[i]){
    ans = ans && DFS(j, !c);
  }

  return ans;
}

bool Solve(){
  int n;
  scanf("%d", &n);

  Reset(n);

  for(int i = 1; i <= n; ++i){
    int a, b;
    scanf("%d%d", &a, &b);
    adj[a].push_back(b);
    adj[b].push_back(a);
  }

  for(int i = 1; i <= n; ++i){
    if(!DFS(i, color[i])){
      return false;
    }
  }

  return true;
}

int main(){
  int t;
  scanf("%d", &t);
  while(t--){
    printf("%s\n", Solve() ? "YES" : "NO");
  }
  return 0;
}