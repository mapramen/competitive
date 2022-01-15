#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 100001

vector<vector<pii>> adj(N);
int weight[N];

void DFS(int i, int p, int w){
  for(auto [j, x]: adj[i]){
    if(j == p){
      continue;
    }
    weight[x] = w;
    DFS(j, i, 5 - w);
  }
}

void Solve(){
  int n;
  scanf("%d", &n);

  for(int i = 1; i <= n; ++i){
    adj[i].clear();
  }

  for(int x = 1; x < n; ++x){
    int i, j;
    scanf("%d%d", &i, &j);
    adj[i].push_back({j, x});
    adj[j].push_back({i, x});
  }

  for(int i = 1; i <= n; ++i){
    if(adj[i].size() > 2){
      printf("-1\n");
      return;
    }
  }

  int root = 1;
  for( ; adj[root].size() == 2; ++root);

  DFS(root, 0, 2);

  for(int x = 1; x < n; ++x){
    printf("%d ", weight[x]);
  }
  printf("\n");
}

int main(){
  int t;
  scanf("%d", &t);
  while(t--){
    Solve();
  }
  return 0;
}