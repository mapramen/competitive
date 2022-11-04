#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define edge tuple<double,int,int>
#define N 1001

int x[N], y[N], parent[N];

void Reset(int n){
  for(int i = 1; i <= n; ++i){
    parent[i] = i;
  }
}

double Dis(int x1, int y1, int x2, int y2){
  int dx = x2 - x1, dy = y2 - y1;
  return sqrt(dx * dx + dy * dy);
}

int Find(int i){
  return parent[i] == i ? i : parent[i] = Find(parent[i]);
}

bool Union(int i, int j){
  i = Find(i), j = Find(j);
  if(i == j){
    return false;
  }

  if(i > j){
    swap(i, j);
  }

  parent[j] = i;
  return true;
}

pair<double,double> Solve(){
  int n, r, m, u, v;
  scanf("%d%d%d%d%d", &n, &r, &m, &u, &v);

  for(int i = 1; i <= n; ++i){
    scanf("%d%d", &x[i], &y[i]);
  }

  vector<edge> edges;
  for(int i = 1; i <= n; ++i){
    for(int j = i + 1; j <= n; ++j){
      edges.push_back({Dis(x[i], y[i], x[j], y[j]), i, j});
    }
  }

  Reset(n);

  int total_components = n;
  double ansu = 0, ansv = 0;

  sort(edges.begin(), edges.end());
  for(edge e: edges){
    double w;
    int i, j;
    tie(w, i, j) = e;

    if(!Union(i, j)){
      continue;
    }

    ansu += (w <= r ? w * u : 0);
    ansv += (w > r ? w * v : 0);

    if(--total_components == m){
      break;
    }
  }

  return {ansu, ansv};
}

int main(){
  int t;
  scanf("%d", &t);
  for(int k = 1; k <= t; ++k){
    pair<double,double> ans = Solve();
    printf("Caso #%d: %.3lf %.3lf\n", k, ans.first, ans.second);
  }
  return 0;
}