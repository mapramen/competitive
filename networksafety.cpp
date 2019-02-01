#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define pli pair<ll,int>
#define PB push_back
#define MP make_pair
#define N 500001
#define MOD 1000000007

int parent[N], u[N], v[N];
ll a[N], p2[N];
pli V[N];

int Find(int i){
  return parent[i] == i ? i : parent[i] = Find(parent[i]);
}

int Union(int i, int j){
  i = Find(i), j = Find(j);

  if(i == j){
    return 0;
  }

  if(i > j){
    swap(i, j);
  }

  parent[j] = i;

  return 1;
}

int main(){
  int n, m, k;

  scanf("%d%d%d", &n, &m, &k);

  for(int i = 1; i <= n; ++i){
    scanf("%lld", &a[i]);
  }

  for(int x = 1; x <= m; ++x){
    scanf("%d%d", &u[x], &v[x]);
    V[x] = MP((a[u[x]] ^ a[v[x]]), x);
  }

  sort(V + 1, V + m + 1);

  p2[0] = 1;
  for(int i = 1; i <= n; ++i){
    p2[i] = (2 * p2[i - 1]) % MOD;
    parent[i] = i;
  }

  ll ans = 0, totalMasks = ((1ll << k)) % MOD;
  for(int i = 1; i <= m; ){
    int connectComponentCount = n, j;
    for(j = i; j <= m && V[j].first == V[i].first; ++j){
      int x = V[j].second;
      connectComponentCount -= Union(u[x], v[x]);
    }
    ans = (ans + p2[connectComponentCount]) % MOD;
    totalMasks = (totalMasks + MOD - 1) % MOD;
    for( ; i < j; ++i){
      int x = V[i].second;
      parent[u[x]] = u[x];
      parent[v[x]] = v[x];
    }
  }

  ans = (ans + totalMasks * p2[n]) % MOD;

  printf("%lld\n", ans);

  return 0;
}
