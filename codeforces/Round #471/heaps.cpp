#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 300001
#define LOGN 19

vector< vector<int> > adj(N), a(N);
int parent[N], c[N], d[N], cx[N];
ll s[N];

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
  start[i] = timer;
  t_time[timer++] = i;
  indx[i] = ind;
  T[0][ind++] = start[i];
  parent[i] = p;

  for(auto k : adj[i]){
    if(k == p)
      continue;
    DFS(k, i);
    ++c[i];
    d[i] = max(d[i], d[k]);
    T[0][ind++] = start[i];
  }

  finish[i] = timer;
  ++d[i];
}

void AnsDFS(int i){
  for(auto k : adj[i]){
    if(k == parent[i])
      continue;
    AnsDFS(k);
    s[i] += s[k];
  }
}

bool cmp(int i, int j){
  return start[i] < start[j];
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

  DFS(1, 0);
  BuildLCASparseTable(n);

  for(int i = 1; i <= n; ++i)
    a[c[i]].PB(i);

  vector<int> b;
  for(int k = n; k > 1; --k){
    for(auto x : a[k])
      b.PB(x);

    vector<int> v(b.begin(), b.end());

    while(v.size()){
      vector<int> u;
      sort(v.begin(), v.end(), cmp);

      ++s[v[0]];
      for(int x = 1; x < v.size(); ++x){
        int l = LCA(v[x], v[x - 1]);
        ++s[v[x]];
        --s[l];
      }

      for(auto i : v){
        int j = parent[i];
        ++cx[j];
        if(cx[j] == k)
          u.PB(j);
      }

      for(auto i : v)
        cx[parent[i]] = 0;

      swap(v, u);
    }
  }

  AnsDFS(1);

  ll ans = 1ll * (n - 1) * n;

  for(int i = 1; i <= n; ++i)
    ans += (d[i] + s[i]);

  printf("%lld\n", ans);

  return 0;
}
