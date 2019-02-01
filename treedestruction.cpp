#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define tiii tuple< int, int, int >
#define PB push_back
#define MP make_pair
#define MT make_tuple
#define N 200001
#define LOGN 18

vector< vector<int> > adj(N);
int parent[N], d[N], c[N];
bool visited[N];

//------------------------------------- LCA -------------------------------------//
int start[N], finish[N], t_time[N], indx[N], ind = 1, timer = 1, T[LOGN + 1][2 * N], lg[2 * N];

void BuildLCASparseTable(int n){
  n = (n << 1);

  for(int i = 2; i < n; i++)
    lg[i] = 1 + lg[i / 2];

  for(int k = 1; (1 << k) < n; k++)
    for(int i = 1, j = 1 + (1 << (k - 1)), m = n - (1 << k) + 1; i < m; i++, j++)
      T[k][i] = min(T[k - 1][i], T[k - 1][j]);
}

int LCA(int x, int y){
  x = indx[x], y = indx[y];

  if(x > y) swap(x,y);

  int k = lg[y - x + 1];
  k = min(T[k][x], T[k][y - (1 << k) + 1]);
  int z = t_time[k];
  return z;
}
//----------------------------------- LCA Ends -----------------------------------//

int FarthestNode(int s, int n){
  int ans = s;

  queue<int> Q;
  Q.push(s);
  visited[s] = 1;

  while(!Q.empty()){
    int i = Q.front();
    Q.pop();

    ans = i;

    for(auto k : adj[i]){
      if(visited[k] == 0){
        visited[k] = 1;
        Q.push(k);
      }
    }
  }

  for(int i = 1; i <= n; ++i)
    visited[i] = 0;

  return ans;
}

void DFS(int i){
  start[i] = timer;
  t_time[timer++] = i;
  indx[i] = ind;
  T[0][ind++] = start[i];
  visited[i] = 1;
  d[i] = 1 + d[parent[i]];

  for(auto k : adj[i]){
    if(visited[k] == 0){
      parent[k] = i;
      ++c[i];
      DFS(k);
      T[0][ind++] = start[i];
    }
  }

  finish[i] = timer;
}

int D(int u, int v){
  int w = LCA(u, v);
  return (d[u] - d[w]) + (d[v] - d[w]);
}

int main(){
  int n;

  scanf("%d", &n);

  for(int x = 1; x < n; ++x){
    int i, j;
    scanf("%d%d", &i, &j);
    adj[i].PB(j);
    adj[j].PB(i);
  }

  int r1 = FarthestNode(1, n);

  DFS(r1);
  BuildLCASparseTable(n);

  int r2 = 0;
  for(int i = 1, x = -1; i <= n; ++i){
    if(d[i] > x && i != r1){
      x = d[i];
      r2 = i;
    }
  }

  queue<int> Q;
  for(int i = 1; i <= n; ++i){
    if(c[i] == 0 && i != r2)
      Q.push(i);
  }

  ll ans = 0;
  vector< tiii > v;

  while(!Q.empty()){
    int i = Q.front();
    Q.pop();

    int d1 = D(r1, i), d2 = D(r2, i);
    if(d1 > d2){
      ans += d1;
      v.PB(MT(r1, i, i));
    }
    else{
      ans += d2;
      v.PB(MT(r2, i, i));
    }

    int k = parent[i];
    --c[k];

    if(c[k] == 0)
      Q.push(k);
  }

  while(r2 != r1){
    ans += (d[r2] - 1);
    v.PB(MT(r1, r2, r2));
    r2 = parent[r2];
  }

  printf("%lld\n", ans);
  for(auto t : v){
    int i, j, k;
    tie(i, j, k) = t;
    printf("%d %d %d\n", i, j, k);
  }

  return 0;
}
