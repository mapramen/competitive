#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 200001

vector<vector<int>> adj(N);
int c[N], parent[N];

void Reset(int n){
  for(int i = 1; i <= n; ++i){
    adj[i].clear(), c[i] = 0, parent[i] = 0;
  }
}

void DFS(int i, int p){
  parent[i] = p;
  for(int j: adj[i]){
    if(j == p){
      continue;
    }
    DFS(j, i);
    c[i] += c[j];
  }
}

int Solve(){
  int n, k;
  scanf("%d%d", &n, &k);

  Reset(n);

  int x, y;
  scanf("%d%d", &x, &y);
  c[x] = 1, c[y] = 1;

  while(k--){
    int z;
    scanf("%d", &z);
    c[z] = 1;
  }

  for(int e = 1; e < n; ++e){
    int i, j;
    scanf("%d%d", &i, &j);
    adj[i].push_back(j);
    adj[j].push_back(i);
  }

  DFS(x, 0);

  int ans = 0;
  for(int i = 1; i <= n; ++i){
    ans += 2 * (i != x && c[i] != 0);
  }

  for(int i = y; i != x; i = parent[i]){
    --ans;
  }

  return ans;
}

int main(){
  int t;
  scanf("%d", &t);
  while(t--){
    printf("%d\n", Solve());
  }
  return 0;
}