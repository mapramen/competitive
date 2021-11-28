#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 200001

vector<vector<int>> adj(N), V(2);
int p[N];
bool marked[N];

void DFS(int i, int p, int color){
  for(int j: adj[i]){
    if(j == p){
      continue;
    }
    DFS(j, i, 1 ^ color);
  }
  V[color].push_back(i);
}

void Solve(){
  int n;
  scanf("%d", &n);

  for(int x = 1; x < n; ++x){
    int i, j;
    scanf("%d%d", &i, &j);
    adj[i].push_back(j);
    adj[j].push_back(i);
  }

  DFS(1, 0, 0);

  if(V[1].size() < V[0].size()){
    swap(V[0], V[1]);
  }

  for(int k = 0, m = V[0].size(), i = 0; (1 << k) <= m; ++k){
    if((m & (1 << k)) == 0){
      continue;
    }

    int l = (1 << k), r = min(n, (1 << (k + 1)) - 1);
    for(int x = l; x <= r; ++x, ++i){
      p[V[0][i]] = x;
      marked[x] = true;
    }
  }

  for(int i = 0, m = V[1].size(), x = 1; i < m; ++i){
    for( ; x < N && marked[x]; ++x);
    p[V[1][i]] = x;
    marked[x] = true;
  }

  V[0].clear(), V[1].clear();
  for(int i = 1; i <= n; ++i){
    adj[i].clear();
    marked[i] = false;
  }

  for(int i = 1; i <= n; ++i){
    printf("%d ", p[i]);
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