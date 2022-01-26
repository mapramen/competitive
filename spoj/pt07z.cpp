#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 10001

vector<vector<int>> adj(N);

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

int main(){
  int n;
  scanf("%d", &n);

  for(int x = 1; x < n; ++x){
    int i, j;
    scanf("%d%d", &i, &j);
    adj[i].push_back(j);
    adj[j].push_back(i);
  }

  printf("%d\n", DFS(1, 0).first);
  
  return 0;
}