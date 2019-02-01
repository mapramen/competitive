#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 50
#define MAXITER 100000

char s[N][N];
int parent[N], graphSize[N], vertexMap[N], c[N];
bool used[N];
vector< vector<int> > adj(N);

int Find(int i){
  return (i == parent[i]) ? i : parent[i] = Find(parent[i]);
}

void Union(int i, int j){
  i = Find(i), j = Find(j);

  if(i == j)
    return ;

  if(i > j)
    swap(i, j);

  parent[j] = i;
  graphSize[i] += graphSize[j];
}

int MinKColorability(int n){
  int ans = n;
  vector<int> p(n);
  iota(p.begin(), p.end(), 1);

  for(int x = 0; x < MAXITER; ++x){
    int ansx = 0;

    for(int j = 1; j <= n; ++j)
      c[j] = 0;

    for(auto i : p){
      for(int j = 1; j <= n + 1; ++j)
        used[j] = false;

      for(auto k : adj[i])
        used[c[k]] = true;

      for(int j = 1; j <= n + 1; ++j){
        if(!used[j]){
          c[i] = j;
          break;
        }
      }

      ansx = max(ansx, c[i]);

      if(ansx > n)
        break;
    }

    ans = min(ans, ansx);
    random_shuffle(p.begin(), p.end());
  }

  return ans;
}

int main(){
  int n;

  scanf("%d", &n);

  for(int i = 0; i < n; ++i)
    scanf("%s", s[i]);

  for(int i = 1; i <= n; ++i){
    parent[i] = i;
    graphSize[i] = 1;
  }

  for(int i = 1; i <= n; ++i){
    for(int j = 1; j <= n; ++j){
      if(s[i - 1][j - 1] == 'A'){
        Union(i, j);
      }
    }
  }

  for(int i = 1; i <= n; ++i){
    for(int j = 1; j <= n; ++j){
      if(s[i - 1][j - 1] == 'X' && Find(i) == Find(j)){
        printf("-1\n");
        return 0;
      }
    }
  }

  int m = 0, ones = 0;
  for(int i = 1; i <= n; ++i){
    if(Find(i) != i)
      continue;
    if(graphSize[i] == 1)
      ++ones;
    else
      vertexMap[i] = ++m;
  }

  for(int i = 1; i <= n; ++i){
    for(int j = 1; j <= n; ++j){
      int x = Find(i), y = Find(j);
      if(graphSize[x] == 1 || graphSize[y] == 1)
        continue;
      if(s[i - 1][j - 1] == 'X'){
        int mx = vertexMap[x], my = vertexMap[y];
        adj[mx].PB(my);
      }
    }
  }

  int ans = n - 1 + MinKColorability(m);

  printf("%d\n", ans);

  return 0;
}
