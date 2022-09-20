#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 100001
#define B 60

vector<vector<pii>> V(B);
int parent[N];

void Reset(int n){
  for(int k = 0; k < B; ++k){
    V[k].clear();
  }

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

int Solve(){
  int n, m;
  scanf("%d%d", &n, &m);

  Reset(n);

  while(m--){
    int i, j;
    ll w;
    scanf("%d%d%lld", &i, &j, &w);
    V[__builtin_ctzll(w)].push_back({i, j});
  }

  int ans = 0;
  for(int k = 0; k < B; ++k){
    for(pii& edge: V[k]){
      ans += Union(edge.first, edge.second) * k;
    }
  }

  return ans + 1;
}

int main(){
  int t;
  scanf("%d", &t);
  while(t--){
    printf("%d\n", Solve());
  }
  return 0;
}