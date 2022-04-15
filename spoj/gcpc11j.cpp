#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 100001

vector<vector<int>> adj(N);

void Reset(int n){
  for(int i = 1; i <= n; ++i){
    adj[i].clear();
  }
}

pii DFS(int i, int p){
  int pathi = 0, depthi = 0;

  for(int j: adj[i]){
    if(j == p){
      continue;
    }
    
    int pathj, depthj;
    tie(pathj, depthj) = DFS(j, i);
    
    pathi = max(pathi, pathj);
    pathi = max(pathi, depthi + 1 + depthj);
    depthi = max(depthi, 1 + depthj);
  }

  return {pathi, depthi};
}

int Solve(){
  int n;
  scanf("%d", &n);

  Reset(n);

  for(int e = 1; e < n; ++e){
    int i, j;
    scanf("%d%d", &i, &j);

    ++i, ++j;
    adj[i].push_back(j);
    adj[j].push_back(i);
  }

  return (DFS(1, 0).first + 1) / 2;
}

int main(){
  int t;
  scanf("%d", &t);
  while(t--){
    printf("%d\n", Solve());
  }
  return 0;
}