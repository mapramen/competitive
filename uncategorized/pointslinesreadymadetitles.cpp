#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define N 200001
#define MOD 1000000007

int n, m, x[N], y[N], parent[N], v[N], e[N], p[N];

void PreProcess(){
  vector<int> c;

  for(int i = 1; i <= m; ++i)
    c.PB(x[i]), c.PB(y[i]);

  sort(c.begin(), c.end());
  c.erase(unique(c.begin(), c.end()), c.end());

  for(int i = 1; i <= m; ++i){
    x[i] = lower_bound(c.begin(), c.end(), x[i]) - c.begin() + 1;
    y[i] = lower_bound(c.begin(), c.end(), y[i]) - c.begin() + 1;
  }

  n = c.size();

  for(int i = 1; i <= n; ++i)
    parent[i] = i, v[i] = 1, e[i] = 0;

  p[0] = 1;
  for(int i = 1; i <= n; ++i)
    p[i] = (2 * p[i - 1]) % MOD;
}

int Find(int i){
  if(i == parent[i])
    return i;
  else
    return (parent[i] = Find(parent[i]));
}

void Union(int i, int j){
  i = Find(i), j = Find(j);
  if(i > j)
    swap(i, j);
  if(i == j)
    ++e[i];
  else{
    v[i] += v[j];
    e[i] += (1 + e[j]);
    parent[j] = i;
  }
}

int main(){
  ll ans = 1;

  scanf("%d", &m);

  for(int k = 1; k <= m; ++k){
    int i, j;
    scanf("%d%d", &i, &j);
    i = i + i, j = j + j + 1;
    x[k] = i, y[k] = j;
  }

  PreProcess();

  for(int k = 1; k <= m; ++k)
    Union(x[k], y[k]);

  for(int i = 1; i <= n; ++i){
    if(Find(i) != i)
      continue;
    if(e[i] >= v[i])
      ans = (ans * p[v[i]]) % MOD;
    else
      ans = (ans * (p[v[i]] + MOD - 1)) % MOD;
  }

  printf("%lld\n", ans);

  return 0;
}
