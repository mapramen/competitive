#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define tiii tuple<int,int,int>
#define N 1001

int parent[N];

void Reset(int n){
  for(int i = 1; i <= n; ++i){
    parent[i] = i;
  }
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

ll Solve(){
  int p, n, m;
  scanf("%d%d%d", &p, &n, &m);

  vector<tiii> edges;
  while(m--){
    int i, j, w;
    scanf("%d%d%d", &i, &j, &w);
    edges.push_back({w, i, j});
  }
  sort(edges.begin(), edges.end());

  Reset(n);

  ll ans = 0;
  for(tiii& edge: edges){
    int w = get<0>(edge), i = get<1>(edge), j = get<2>(edge);
    if(Union(i, j)){
      ans += w;
    }
  }

  return p * ans;
}

int main(){
  int t;
  scanf("%d", &t);
  while(t--){
    printf("%lld\n", Solve());
  }
  return 0;
}