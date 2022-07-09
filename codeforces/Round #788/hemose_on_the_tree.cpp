#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define B 17
#define N ((1 << 17) + 1)

vector<vector<pii>> adj(N);
int edge_child[N];
bool higher[N];

void Reset(int n){
  for(int i = 1; i <= n; ++i){
    adj[i].clear();
  }
}

void DFS(int i, int p){
  higher[i] = !higher[p];
  for(auto [j, e]: adj[i]){
    if(j == p){
      continue;
    }
    edge_child[e] = j;
    DFS(j, i);
  }
}

void Solve(){
  int p;
  scanf("%d", &p);

  int n = (1 << p);
  Reset(n);

  for(int e = 1; e < n; ++e){
    int i, j;
    scanf("%d%d", &i, &j);
    adj[i].push_back({j, e});
    adj[j].push_back({i, e});
  }

  DFS(1, 0);

  printf("1\n");

  for(int i = 1; i <= n; ++i){
    int ans = (i - 1) + (higher[i] ? n : 0);
    printf("%d ", ans);
  }
  printf("\n");

  for(int e = 1; e < n; ++e){
    int i = edge_child[e];
    int ans = (i - 1) + (higher[i] ? 0 : n);
    printf("%d ", ans);
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