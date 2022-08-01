#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define tiii tuple<int,int,int>
#define N 300001

int parent[N], sz[N], qans[N];
vector<tiii> edges;
vector<pii> queries;

void Reset(int n){
  for(int i = 1; i <= n; ++i){
    parent[i] = i, sz[i] = 1;
  }
}

int Find(int i){
  return parent[i] == i ? i : parent[i] = Find(parent[i]);
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
  sz[i] += sz[j];
}

int main(){
  int n, m, q;
  scanf("%d%d%d", &n, &m, &q);

  while(m--){
    int i, j, w;
    scanf("%d%d%d", &i, &j, &w);
    edges.push_back({w, i + 1, j + 1});
  }

  for(int k = 0; k < q; ++k){
    int i, w;
    scanf("%d%d", &i, &w);
    queries.push_back({w, i + 1});
  }

  vector<int> query_indexes(queries.size());
  iota(query_indexes.begin(), query_indexes.end(), 0);

  sort(edges.begin(), edges.end());
  sort(query_indexes.begin(), query_indexes.end(), [](int i, int j) { return queries[i] > queries[j]; });

  Reset(n);

  for(int k: query_indexes){
    int qw, qi;
    tie(qw, qi) = queries[k];

    for( ; !edges.empty() && get<0>(edges.back()) >= qw; edges.pop_back()){
      Union(get<1>(edges.back()), get<2>(edges.back()));
    }

    qans[k] = sz[Find(qi)];
  }

  for(int k = 0; k < q; ++k){
    printf("%d\n", qans[k]);
  }

  return 0;
}