#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 100001

vector< vector<int> > adj(N), v(N);
int parent[N], ans[N];
bool valid[N];

int Find(int i){
  if(parent[i] != i)
    parent[i] = Find(parent[i]);
  return parent[i];
}

int Union(int i, int j){
  i = Find(i), j = Find(j);
  if(i == j)
    return 0;
  else{
    parent[i] = parent[j] = min(i, j);
    return 1;
  }
}

int main(){
  int t;

  scanf("%d", &t);
  while(t--){
    int n, m;

    scanf("%d%d", &n, &m);

    for(int i = 1; i <= n; i++){
      parent[i] = i;
      adj[i].clear();
      v[i].clear();
      valid[i] = 0;
    }

    for(int x = 1; x <= m; x++){
      int i, j;
      scanf("%d%d", &i, &j);
      adj[i].PB(j);
      adj[j].PB(i);
    }

    for(int i = 1; i <= n; i++)
      v[adj[i].size()].PB(i);

    ans[n - 1] = n - 1;
    for(int d = n - 2; d > -1; d--){
      ans[d] = ans[d + 1];
      for(auto i : v[d + 1])
        valid[i] = 1;
      for(auto i : v[d + 1]){
        for(auto j : adj[i]){
          if(valid[j])
            ans[d] -= Union(i, j);
        }
      }
    }

    for(int d = 0; d < n; d++)
      printf("%d ", ans[d]);
    printf("\n");
  }
  
  return 0;
}
