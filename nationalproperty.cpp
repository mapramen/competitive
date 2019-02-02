#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 100001

vector< vector<int> > v(N), adj(N);
int inDegree[N], a[N], visited[N];

void DFS(int i){
  visited[i] = 1;
  for(auto k : adj[i]){
    if(visited[k])
      continue;
    a[k] = a[i];
    DFS(k);
  }
}

int main(){
  int n, m, c = 0;

  scanf("%d%d", &n, &m);

  for(int x = 1; x <= n; ++x){
    int k;
    scanf("%d", &k);
    while(k--){
      int i;
      scanf("%d", &i);
      v[x].PB(i);
    }
  }

  for(int x = n - 1; x > 0; --x){
    int f = 0;
    for(int i = 0, k = min(v[x].size(), v[x + 1].size()); i < k; ++i){
      int p = v[x][i], q = v[x + 1][i];
      if(p != q){
        f = 1;
        if(p > q)
          a[p] = 1;
        else{
          adj[q].PB(p);
          ++inDegree[p];
        }
        break;
      }
    }

    if(f == 0 && v[x].size() > v[x + 1].size()){
      printf("No\n");
      return 0;
    }
  }

  for(int i = 1; i <= m; ++i){
    if(inDegree[i] == 0 && a[i] == 1)
      DFS(i);
  }

  for(int x = n - 1; x > 0; --x){
    for(int i = 0, k = min(v[x].size(), v[x + 1].size()); i < k; ++i){
      int p = v[x][i], q = v[x + 1][i];
      p -= N * a[p];
      q -= N * a[q];
      if(p != q){
        if(p > q){
          printf("No\n");
          return 0;
        }
        break;
      }
    }
  }

  for(int i = 1; i <= m; ++i)
    c += a[i];

  printf("Yes\n%d\n", c);
  for(int i = 1; i <= m; ++i){
    if(a[i])
      printf("%d ", i);
  }
  printf("\n");

  return 0;
}
