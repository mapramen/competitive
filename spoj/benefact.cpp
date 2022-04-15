#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 50001

vector<vector<pii>> adj(N);

void Reset(int n){
  for(int i = 1; i <= n; ++i){
    adj[i].clear();
  }
}

pii DFS(int i, int p){
  int max_length_path = 0, max_depth = 0;

  for(pii& edge: adj[i]){
    int j = edge.first, w = edge.second;
    if(j == p){
      continue;
    }

    pii ansx = DFS(j, i);
    int depth = w + ansx.second;

    max_length_path = max(max_length_path, max(ansx.first, max_depth + depth));
    max_depth = max(max_depth, depth);
  }

  return {max_length_path, max_depth};
}

int Solve(){
  int n;
  scanf("%d", &n);

  Reset(n);

  for(int e = 1; e < n; ++e){
    int i, j, w;
    scanf("%d%d%d", &i, &j, &w);
    adj[i].push_back({j, w});
    adj[j].push_back({i, w});
  }

  return DFS(1, 0).first;
}

int main(){
  int t;
  scanf("%d", &t);
  while(t--){
    printf("%d\n", Solve());
  }
  return 0;
}