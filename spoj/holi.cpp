#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define pil pair<int,ll>
#define N 100001

vector<vector<pii>> adj(N);

void Reset(int n){
  for(int i = 1; i <= n; ++i){
    adj[i].clear();
  }
}

pil DFS(int n, int i, int p){
  int szi = 1;
  ll ansi = 0;
  
  for(pii& edge: adj[i]){
    int j = edge.first, w = edge.second;
    if(j == p){
      continue;
    }

    pil dfsj = DFS(n, j, i);
    int szj = dfsj.first;
    
    szi += szj;
    ansi += 1ll * min(szj, n - szj) * w + dfsj.second;
  }

  return {szi, ansi};
}

ll Solve(){
  int n;
  scanf("%d", &n);

  Reset(n);

  for(int e = 1; e < n; ++e){
    int i, j, w;
    scanf("%d%d%d", &i, &j, &w);
    adj[i].push_back({j, w});
    adj[j].push_back({i, w});
  }

  return 2 * DFS(n, 1, 0).second;
}

int main(){
  int t;
  scanf("%d", &t);
  for(int k = 1; k <= t; ++k){
    printf("Case #%d: %lld\n", k, Solve());
  }
  return 0;
}