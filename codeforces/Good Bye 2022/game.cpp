#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define N 100001
#define MOD 998244353 

int a[N], b[N];
int parent[N], sz[N], edge_cnt[N];
bool self_loop[N];

void Reset(int n){
  for(int i = 1; i <= n; ++i){
    parent[i] = i, sz[i] = 1, edge_cnt[i] = 0;
    self_loop[i] = false;
  }
}

int Find(int i){
  return parent[i] == i ? i : parent[i] = Find(parent[i]);
}

void Union(int i, int j){
  if(i == j){
    self_loop[Find(i)] = true;
  }

  i = Find(i), j = Find(j);
  if(i == j){
    ++edge_cnt[i];
    return;
  }

  if(i > j){
    swap(i, j);
  }

  parent[j] = i;
  sz[i] += sz[j];
  edge_cnt[i] += edge_cnt[j] + 1;
  self_loop[i] = self_loop[i] || self_loop[j];
}

int Solve(){
  int n;
  scanf("%d", &n);

  for(int i = 1; i <= n; ++i){
    scanf("%d", &a[i]);
  }

  for(int i = 1; i <= n; ++i){
    scanf("%d", &b[i]);
  }

  Reset(n);

  for(int i = 1; i <= n; ++i){
    Union(a[i], b[i]);
  }

  int ans = 1;
  for(int i = 1; i <= n; ++i){
    if(Find(i) != i){
      continue;
    }

    if(edge_cnt[i] != sz[i]){
      ans = 0;
      break;
    }

    ans = (1ll * ans * (self_loop[i] ? n : 2)) % MOD;
  }

  return ans;
}

int main(){
  int t;
  scanf("%d", &t);
  while(t--){
    printf("%d\n", Solve());
  }
  return 0;
}