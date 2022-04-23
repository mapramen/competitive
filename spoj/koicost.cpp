#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define tiii tuple<int,int,int>
#define N 100001
#define MOD 1000000000

int parent[N], sz[N];

int Find(int i){
  return i == parent[i] ? i : parent[i] = Find(parent[i]);
}

ll Union(int i, int j){
  i = Find(i), j = Find(j);
  if(i == j){
    return 0;
  }

  if(i > j){
    swap(i, j);
  }

  parent[j] = i;
  sz[i] += sz[j];

  return 1ll * (sz[i] - sz[j]) * sz[j];
}

int main(){
  int n, m;
  scanf("%d%d", &n, &m);

  vector<tiii> edges;
  while(m--){
    int i, j, w;
    scanf("%d%d%d", &i, &j, &w);
    edges.push_back({w, i, j});
  }

  for(int i = 1; i <= n; ++i){
    parent[i] = i, sz[i] = 1;
  }

  sort(edges.begin(), edges.end(), greater<tiii>());

  ll c = 0, ans = 0;
  for(tiii& edge: edges){
    c += Union(get<1>(edge), get<2>(edge));
    ans += c * get<0>(edge);
  }

  printf("%lld\n", ans % MOD);

  return 0;
}