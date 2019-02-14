#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 100001
#define LOGN 17

vector< vector<int> > adj(N);
int d[N];

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

void DFS(int i, int p){
  d[i] = d[p] + 1;
  start[i] = timer;
  t_time[timer++] = i;
  indx[i] = ind;
  T[0][ind++] = start[i];

  for(auto k : adj[i]){
    if(k == p)
      continue;
    DFS(k, i);
    T[0][ind++] = start[i];
  }

  finish[i] = timer;
}

bool IsAncestor(int i, int j){
  return (start[i] <= start[j] && finish[j] <= finish[i]);
}

int Distance(int i, int j){
  int k = LCA(i, j);
  return (d[i] - d[k]) + (d[j] - d[k]);
}

int GetAns(int a, int b, int c){
  if(IsAncestor(b, a))
    swap(a, b);

  if(IsAncestor(a, b)){
    if(IsAncestor(c, a))
      return Distance(a, c);
    else if(IsAncestor(b, c))
      return Distance(b, c);
    else if(IsAncestor(a, c)){
      if(IsAncestor(c, b))
        return 0;
      else
        return Distance(LCA(b, c), c);
    }
    else
      return Distance(a, c);
  }
  else{
    if(IsAncestor(a, c))
      return Distance(a, c);
    else if(IsAncestor(b, c))
      return Distance(b, c);
    else{
      int k = LCA(a, b);
      if(IsAncestor(k, c)){
        if(LCA(a, c) != k)
          return Distance(LCA(a, c), c);
        else if(LCA(b, c) != k)
          return Distance(LCA(b, c), c);
        else
          return Distance(k, c);
      }
      else
        return Distance(k, c);
    }
  }
}

void GetPath(int s, int t){
  map< int, int > parent;
  queue<int> Q;

  parent[s] = s;
  Q.push(s);
  while(parent.find(t) == parent.end()){
    int i = Q.front();
    Q.pop();
    for(auto k : adj[i]){
      if(parent.find(k) != parent.end())
        continue;
      parent[k] = i;
      Q.push(k);
    }
  }

  printf("Path %d -> %d:\n", t, s);
  while(t != s){
    printf("%d %d\n", t, d[t]);
    t = parent[t];
  }
  printf("%d %d\n\n", s, d[s]);
}

int main(){
  int n, q;

  scanf("%d%d", &n, &q);

  for(int i = 2, j; i <= n; i++){
    scanf("%d", &j);
    adj[i].PB(j);
    adj[j].PB(i);
  }

  DFS(1, 0);
  BuildLCASparseTable(n);

  while(q--){
    int a, b, c, ans = 0;
    scanf("%d%d%d", &a, &b, &c);
    ans = max(ans, GetAns(a, b, c));
    ans = max(ans, GetAns(a, c, b));
    ans = max(ans, GetAns(b, c, a));
    printf("%d\n", ans + 1);
  }

  return 0;
}
