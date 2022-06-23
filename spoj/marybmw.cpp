#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define edge tuple<ll,int,int>
#define N 50001

int parent[N];

void Reset(int n){
  for(int i = 1; i <= n; ++i){
    parent[i] = i;
  }
}

int Find(int i){
  return parent[i] == i ? parent[i] : parent[i] = Find(parent[i]);
}

void Union(int i, int j){
  i = Find(i), j = Find(j);
  if(i == j){
    return;
  }

  if(i > j){
    swap(i, j);
  }

  parent[j] = i;
}

ll Solve(){
  int n, m;
  scanf("%d%d", &n, &m);

  vector<edge> edges;
  while(m--){
    int i, j;
    ll w;
    scanf("%d%d%lld", &i, &j, &w);
    edges.push_back({w, i, j});
  }
  sort(edges.begin(), edges.end(), greater<edge>());

  Reset(n);
  for(edge& t: edges){
    int i, j;
    ll w;
    tie(w, i, j) = t;
    Union(i, j);

    if(Find(n) == Find(1)){
      return w;
    }
  }

  return -1;
}

int main(){
  int t;
  scanf("%d", &t);
  while(t--){
    printf("%lld\n", Solve());
  }
  return 0;
}