#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define tiiii tuple<int,int,int,int>
#define N 200001
#define LOGN 17

vector<vector<pii>> adj(N);
int a[N], d[N], parent[N], maxa[N], mxi[N], toll[N];
pii T[LOGN + 1][N], ans[N];
vector<tiiii> v;

pii KthAncestor(int k, int i){
  int x = k, e = 0;
  
  for(k = LOGN; k > -1; --k){
    if((x & (1 << k)) != 0){
      auto [j, ei] = T[k][i];
      i = j, e = max(e, ei);
      x ^= (1 << k);
    }
  }

  return {i, e};
}

pii LCA(int i, int j){
  if(d[i] > d[j]){
    swap(i, j);
  }

  int e;
  tie(j, e) = KthAncestor(d[j] - d[i], j);

  if(i == j){
    return {i, e};
  }

  for(int k = LOGN; k > -1; --k){
    auto [pi, ei] = T[k][i];
    auto [pj, ej] = T[k][j];

    if(pi != pj){
      i = pi, j = pj;
      e = max(e, max(ei, ej));
    }
  }

  e = max(e, max(T[0][i].second, T[0][j].second));

  return {T[0][i].first, e};
}

int MaxEdgeWeight(int i, int j){
  return LCA(i, j).second;
}

void DFS(int i, int pi, int ei){
  T[0][i] = {pi, ei};
  d[i] = 1 + d[pi];

  for(auto [j, t]: adj[i]){
    if(j == pi){
      continue;
    }
    DFS(j, i, t);
  }
}

int Find(int i){
  return i == parent[i] ? i : parent[i] = Find(parent[i]);
}

void Union(int i, int j){
  i = Find(i), j = Find(j);
  
  if(i > j){
    swap(i, j);
  }

  if(maxa[i] == maxa[j]){
    toll[i] = max(MaxEdgeWeight(mxi[i], mxi[j]), max(toll[i], toll[j]));
  }
  
  if(maxa[i] < maxa[j]){
    maxa[i] = maxa[j], mxi[i] = mxi[j], toll[i] = toll[j];
  }

  parent[j] = i;
}

void PreProcess(int n){
  DFS(1, 0, 0);

  for(int k = 1; k <= LOGN; ++k){
    for(int i = 1; i <= n; ++i){
      auto [j, ei] = T[k - 1][i];
      auto [pj, ej] = T[k - 1][j];
      T[k][i] = {pj, max(ei, ej)};
    }
  }

  for(int i = 1; i <= n; ++i){
    parent[i] = i, maxa[i] = a[i], mxi[i] = i, toll[i] = 0;
  }
}

int main(){
  int n, q;
  scanf("%d%d", &n, &q);

  for(int i = 1; i <= n; ++i){
    scanf("%d", &a[i]);
  }

  for(int x = 1; x < n; ++x){
    int i, j, c, t;
    scanf("%d%d%d%d", &i, &j, &c, &t);
    
    adj[i].push_back({j, t});
    adj[j].push_back({i, t});

    v.push_back({-c, 0, i, j});
  }

  for(int k = 1; k <= q; ++k){
    int i, c;
    scanf("%d%d", &c, &i);

    v.push_back({-c, 1, i, k});
  }

  PreProcess(n);

  sort(v.begin(), v.end());

  for(auto [c, t, i, j]: v){
    if(t == 0){
      Union(i, j);
      continue;
    }

    int pi = Find(i);
    ans[j] = {maxa[pi], max(toll[pi], MaxEdgeWeight(mxi[pi], i))};
  }

  for(int k = 1; k <= q; ++k){
    printf("%d %d\n", ans[k].first, ans[k].second);
  }

  return 0;
}